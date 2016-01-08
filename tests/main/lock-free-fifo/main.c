/**************************************************************************
    BuguRTOS-0.9.x (Bugurt real time operating system)
    Copyright (C) 2015 anonimous

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Please contact with me by E-mail: shkolnick.kun@gmail.com

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes BuguRTOS, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
**************************************************************************/

/*****************************************************************************************
```````````````````````````````..:+oyhdmNNMMMMMMNmmdhyo+:..```````````````````````````````
``````````````````````````.:oydNMMMMMMMMMNNNNNNNNMMMMMMMMMNdy+:.``````````````````````````
```````````````````````:sdNMMMMMNdys+/::----------::/osydNMMMMMNds:```````````````````````
```````````````````.+hNMMMMmho/-..........................-/shmMMMMNh/.```````````````````
````````````````./hNMMMNho:...................................-:ohNMMMNh/`````````````````
``````````````.smMMMNy/-.......:////ss++/+-.......................-+yNMMMmo.``````````````
````````````-sNMMMd+-.....:////:-...-/s::..............+o/-..........-odMMMNs.````````````
``````````.sNMMNh/....................................-o:--............./hMMMNo.``````````
`````````+mMMMh:-........................................-...............-/dMMMm/`````````
```````.yMMMm/...................-::--..................:-........--........+mMMMy.```````
``````:mMMMy-.......................-::-...............-:.........-::........-yMMMd:``````
`````/NMMN+-..................::-.....-:-............../--.........-:/-.......-+NMMN:`````
````+NMMm::o/-..--/+o+o+++++o+osys+//::-::.............:/....-:-::-..-++-.......:NMMN/````
```/NMMm:.-++-+yhs/-``       `dMMMMMmho+:-..............:-/+yho/:/+oyo//o-......./mMMN:```
``-NMMm/....-/--::/o+o+oo+oo++oosyss+smyo/.............:yyho-`     smMMddh-......./NMMN.``
`.hMMM/......-++:-.-:oooooooooosyyhhys/...............-+osyyyyysssssooo+ohhs-......+MMMh.`
`+MMMy.......-::/++:-.....-:/++++o+o/--................--/oooo+o++o+++////-y/.......hMMM/`
.mMMN:.........--:---...-::/+//::--.......................--//+//-...-.....+/......./NMMd`
/MMMy............-::----------....----/+-.....................-++/:---....-o-........hMMN:
yMMM/.............--:://///oo+++/+++oo+-.......................-://+/:--::::.........+MMMs
mMMN:................----:/h:::/:/::---.........................--/osss+++:..........:NMMd
MMMd-....................:mNs:-....................................--:odo:-..........:mMMN
MMMd-....................yoshyoso:--................................../mm/...........:mMMM
MMMm:..................../-o/h.y-:+dooo+/:--....................-/osydddmh...........:mMMN
mMMN:........................+mNs `h.  -d/:/+h++ooooy+++s++y+++mo+y` yh.do...........:NMMh
sMMM+........................-hmMo/ds  oMo`.-o     :h   s:`h` `Nysd.-Ny-h:...........+MMMo
/MMMh........................./smMMMMd+NMMNNMh`    sN: .mNNMddNMMMMNmN+..............hMMN:
.dMMN/........................./+hMMMMMMMMMMMMmhyyyNMNNMMMMMMMMMMMNsoo-............./NMMd`
`+MMMh.........................-/+omMMMMMMMMMMMMMMMMMMMMMMMMMMMMms-/+...............hMMM/`
`.hMMM+..........................:/-omMMMMMMMMMMMMMMMdmMdhMMMds/-..-...............oMMMy``
``.NMMN/............................--/hNN/h.`ys:dmsd:-syos+--+.................../NMMN.``
```/NMMm:...........................:+/--:+s++oo+osoo+/:-..-/+::-................/mMMN:```
````/NMMN:............................-/++/:-..........-//+/-..:+.--............/NMMN/````
`````:NMMN+-.............../+-.............-://////////:-.......+s+::.........-oNMMN:`````
``````:mMMMy-..............:/o-.................................:yo//........-hMMMd-``````
```````.yMMMm+.............:o:++-...............................+y+o-......-+mMMMs.```````
`````````/mMMMd/-...........-++:+/-.---........................-ho+/.....-/dMMMm/`````````
``````````.oNMMMh/............-++:++/////:....................-yo:o-...-+hMMMNo.``````````
````````````.sNMMMdo-...........-++::++:-:/+//:..............:o:/o-..-omMMMNo.````````````
``````````````.omMMMNy+-..........-/+-.:/+/:--:+++/++//:/::/+/-+/.-+hMMMMmo```````````````
`````````````````/hNMMMNho:-...............-:/:-....--::::--..-/ohNMMMNy:`````````````````
```````````````````./hNMMMMmhs/-..........................-/shNMMMMNy/.```````````````````
```````````````````````:sdNMMMMMNdhso+/:----------:/+oshdNMMMMMNho:```````````````````````
``````````````````````````.:+ydNMMMMMMMMMMNNNNNNMMMMMMMMMMmds+:```````````````````````````
````````````````````````````````.:/osyhdmNNMMMMNNmdhyso/:.````````````````````````````````
******************************************************************************************
*                                                                                        *
*                   This logo was graciously delivered by 10003-kun ITT:                 *
*                                                                                        *
*                           http://www.0chan.ru/r/res/9996.html                          *
*                                                                                        *
*****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int lf_st_t;
#define LF_ST_OK (0)
#define LF_ST_EAGAIN (1)
//===============================================================================
typedef struct _lf_item_t lf_item_t; //Lockfree list item;

struct _lf_item_t
{
    volatile int valid;
    lf_item_t * prev;
    lf_item_t * next;
};

//Default compare and swap implementation
#ifndef LF_CAS
#define LF_CAS(var,old,new) __sync_bool_compare_and_swap( &(var), (old), (new))
#endif

#ifndef LF_YELD
#define LF_YELD() do{}while(0)
#endif

void lf_item_init( lf_item_t * item );
lf_st_t lf_item_put( lf_item_t * item, lf_item_t * fifo ); //Put an item to lock-free fifo (can used by multiple threads)
lf_item_t * lf_item_get( lf_item_t * fifo ); //Get an item from lock-free fifo (MUST used by SINGLE thread only!!!)
//===============================================================================
void lf_item_init( lf_item_t * item )
{
    item->prev = item;
    item->next = item;
    item->valid = 0xABCD;
}
//Put an item to lock-free fifo (can used by multiple threads)
///NOTE: THIS FUNCTION IS THREAD SAFE!!!
///NOTE: THIS FUNCTION IS LOCK   FREE!!!
///NOTE: THIS FUNCTION CAN BE USED IN REAL ISR!!!
lf_st_t lf_item_put( lf_item_t * item, lf_item_t * fifo )
{
    //One itteration per interrupt on single processor.
    while(1)
    {
        ///step 1
        //Many threads may call to lf_item_put( item, some_fifo)
        if( LF_CAS( item->prev, item, fifo->prev) )
        {
            ///step 2
            LF_CAS( item->next, item, fifo);
            ///step 3
            //Many threads may call to lf_item_put( some_item, fifo)
            if( LF_CAS( fifo->prev, item->prev, item) )
            {
                break;//May goto step 3a
            }
            else
            {
                //Undo steps 2 and 1 on fail
                //Undos are done in reverse order!!!
                LF_CAS( item->next, item->next, item);
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
    //The last but not the list
    //If item is not going to be geted, do...
    LF_CAS( item->prev->next, fifo, item);

    return LF_ST_OK;
}
//Get an item from lock-free fifo (MUST used by SINGLE thread only!!!)
/// WARNING: THIS FUNCTION IS NOT THREAD SAFE!!!
/// WARNING: THIS FUNCTION IS NOT LOCK FREE!!!
/// NOTE:    BUT IT'S FASTER THAN THREAD SAFE AND LOCKFREE!!!
lf_item_t * lf_item_get( lf_item_t * fifo )
{
    //Check if fifo is empty
    //Some thread may write fifo->prev at the same time, so...
    if( LF_CAS( fifo->prev, fifo, fifo) )
    {
        return (lf_item_t *)0;
    }
    else
    {
        lf_item_t * head;
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
        //Check if there is only one item, and try to cut it with atomic operation.
        if( LF_CAS( fifo->prev, head, fifo) )
        {
            //There was only one item in the fifo
            fifo->next = fifo;
        }
        else
        {
            // wait for step 3b to complete.
            while( LF_CAS( head->next, fifo, fifo) )
            {
                LF_YELD();
            }
            //OK! All links have formed
            head->next->prev = fifo;
            fifo->next = head->next;
        }
        //Now we can handle head->next
        head->next = head;
        return head;
    }
}


lf_item_t tst_item[10];
lf_item_t tst_fifo;

int main()
{
    int i;

    lf_item_t * tst_ret;

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
