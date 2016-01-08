#include <stdio.h>
#include <stdlib.h>

typedef int lf_st_t;
#define LF_ST_OK (0)
#define LF_ST_EAGAIN (1)
//===============================================================================
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
lf_st_t lf_item_put( lf_item * item, lf_item * fifo ); //Put an item to lock-free fifo (can used by multiple threads)
lf_item * lf_item_get( lf_item * fifo ); //Get an item from lock-free fifo (MUST used by SINGLE thread only!!!)
//===============================================================================
void lf_item_init( lf_item * item )
{
    item->prev = item;
    item->next = item;
    item->valid = 0xABCD;
}
//Put an item to lock-free fifo (can used by multiple threads)
lf_st_t lf_item_put( lf_item * item, lf_item * fifo )
{
    while(1)
    {
        ///step 1a
        //Many threads may call to lf_item_put( item, some_fifo)
        if( LF_CAS( item->prev, item, fifo->prev) )
        {
            ///step 2
            //Many threads may call to lf_item_put( some_item, fifo)
            if( LF_CAS( fifo->prev, item->prev, item) )
            {
                break;//May goto step 3a
            }
            else
            {
                //Undo item->prev = fifo->prev before next ettempt
                ///step 1b
                ///WARNING: No LF_YELD here, as lf_item_put must be called from REAL IRSs!!!
                LF_CAS( item->prev, item->prev, item);
                continue;
            }
        }
        else
        {
            //Some other thread has called lf_item_put( item, some_fifo)
            return LF_ST_EAGAIN;
        }
    }
    /// step 3a
    //OK! We are in the fifo;
    //Now we must handle item->prev->next ASAP!
    //Only two threads may write to item->prev->next, they are:
    //this thread and the thread, that called lf_item_put(fifo->prev);
    //So if lf_item_put(fifo->prev) finished, then item->prev->next == fifo
    if( !LF_CAS( item->prev->next, fifo, item) )
    {
        ///step 3b
        //Else item->prev->next should point to item->prev
        if( !LF_CAS( item->prev->next, item->prev, item) )
        {
            //Other item->prev->next values are not valid!!!
            while(1);
        }
    }
    //The last, but not the least: we must handle item->next.
    //If some other thread has interrupted this call, then item->next != item,
    //so try to do item->next = fifo
    ///step 4
    LF_CAS( item->next, item, fifo);
    return LF_ST_OK;
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
            //Only two threads may change head->next, so no more delays
        }
        //Here we can modify fifo->next, and head->next
        fifo->next = head->next;
        head->next = head;
        //Now we must handle fifo->next->prev, it won't be used by ither threads!!
        fifo->next->prev = fifo;

        return head;
    }
}


lf_item tst_item[10];
lf_item tst_fifo;

int main()
{
    int i;

    lf_item * tst_ret;

    (void)tst_ret;//Disable warning!

    for( i = 0; i < 10; i++ )
    {
        lf_item_init( tst_item + i );
    }

    lf_item_init( &tst_fifo );

    lf_item_put( tst_item    , &tst_fifo );
    lf_item_put( tst_item + 1, &tst_fifo );
    lf_item_put( tst_item + 2, &tst_fifo );

    tst_ret = lf_item_get( &tst_fifo );
    tst_ret = lf_item_get( &tst_fifo );
    tst_ret = lf_item_get( &tst_fifo );
    tst_ret = lf_item_get( &tst_fifo );

    printf("Hello world!\n");
    return 0;
}
