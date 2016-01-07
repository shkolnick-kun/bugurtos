#include <stdio.h>
#include <stdlib.h>

typedef struct _lf_item lf_item; //Lockfree list item;

struct _lf_item
{
    volatile int valid;
    lf_item * prev;
    lf_item * next;
};

//Default compare and swap implementation
#ifndef LF_CAS
#define LF_CAS(var,old,new) __sync_bool_compare_and_swap( &(var), (old), (new))
#endif

#ifndef LF_YELD
#define LF_YELD() do{}while(0)
#endif

void lf_item_init( lf_item * item );
void lf_item_put( lf_item * item, lf_item * fifo ); //Put an item to lock-free fifo (can used by multiple threads)
lf_item * lf_item_get( lf_item * fifo ); //Get an item from lock-free fifo (MUST used by SINGLE thread only!!!)
//===============================================================================
void lf_item_init( lf_item * item )
{
    item->prev = item;
    item->next = item;
    item->valid = 0xABCD;
}
//Put an item to lock-free fifo (can used by multiple threads)
void lf_item_put( lf_item * item, lf_item * fifo )
{
    do
    {
        ///step 1
        item->prev = fifo->prev;//Only this thread writes item->prev;
        ///step 2
    }
    while( !LF_CAS( fifo->prev, item->prev, item) );//Many threads may try to write fifo->prev
    /// step 3a
    //OK! We are in the fifo;
    //Now we must handle item->prev->next ASAP!
    //Onle two threads may write to item->prev->next, they are
    //this thread and the thread, that called lf_item_put(fifo->prev);
    //So if lf_item_put(fifo->prev) finished, then item->prev->next == fifo
    if( !LF_CAS( item->prev->next, fifo, item) )
    {
        ///step 3b
        //Else item->prev->next should point to item->prev
        if( !LF_CAS( item->prev->next, item->prev, item) )
        {
            //Other item->prev->next values are not valid!!!
            while(1)
            {
                LF_YELD();//Panic here.
            }
        }
    }
    //The last, but not the least: we must handle item->next.
    //If some other thread has interrupted this call, then item->next != item,
    //so try to do item->next = fifo
    ///step 4
    LF_CAS( item->next, item, fifo);
}
//Get an item from lock-free fifo (MUST used by SINGLE thread only!!!)
/// WARNING: ONLY ONE THREAD IS ALLOWED CALL THIS FUNCTION!!!
lf_item * lf_item_get( lf_item * fifo )
{
    //Check if fifo is empty
    //Some thread may write fifo->prev at the same time, so...
    if( LF_CAS( fifo->prev, fifo, fifo) )
    {
        return (lf_item *)0;
    }
    else
    {
        lf_item * head;
        //Ok, it's not empty, let's cut its head!
        //If other thread called lf_item_put( fifo->prev ),
        //then we must wait for step 3 to complite
        while( LF_CAS( fifo->next, fifo, fifo) )
        {
            LF_YELD();
        }
        //Get the head;
        head = fifo->next;
        //head->prev won't be used until next lf_item_put, so...
        head->prev = head;
        //If some thread called lf_item_put( head->prev ),
        //then we must wait for step 3a/b to complete.
        while( LF_CAS( head->next, head, head) )
        {
            LF_YELD();
        }
        //If one more thread called lf_item_put( head->prev ),
        if( !LF_CAS( fifo->prev, head, head) )
        {
            // wait for step 3b to complete.
            while( LF_CAS( head->next, fifo, fifo) )
            {
                LF_YELD();
            }
        }
        //Here we can modify fifo->next, and head->next
        fifo->next = head->next;
        head->next = head;
        //Now we must handle fifo->next->prev, it won't be used by ither threads!!
        fifo->next->prev = fifo;

        return head;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
