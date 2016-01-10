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
//===============================================================================
typedef int lf_st_t;

#define LF_ST_OK     ((lf_st_t)0)
#define LF_ST_EAGAIN ((lf_st_t)1)
#define LF_ST_EDLOCK ((lf_st_t)2)
#define LF_ST_EEMPTY ((lf_st_t)3)

//===============================================================================
typedef struct _lf_item_t lf_item_t; //Lockfree list item;

struct _lf_item_t
{
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

//Dead lock control
#ifndef LF_DLCT_INIT
#define LF_DLCT_INIT() do{}while(0)
#endif

#ifndef LF_DLCT_FAIL
#define LF_DLCT_FAIL() (0)
#endif
//Методы
/*!
\~russian
\brief
Инициализация объекта типа #lf_item_t.

\warning Для внутреннего использования.

\param item Указатель на объект #lf_item_t.

\~english
\brief
An #lf_item_t object initiation.

\warning Internal usage function.

\param item An #lf_item_t pointer.
*/
void lf_item_init( lf_item_t * item );
//Методы
/*!
\~russian
\brief
Вставка элемента в fifo

\note Эта функция потокобезопасна
\note Этю функцию можно вызывать из прерываний

\param item Указатель на элемент для вставки.
\param fifo Указатель на FIFO.
\return LF_ST_OK или код ошибки.
\~english
\brief
Put an item to a fifo.

\note Thread safe.
\note Interrupt safe.

\param item An item pointer.
\param fifo A FIFO pointer.
\return LF_ST_OK or error code.
*/
lf_st_t lf_item_put( lf_item_t *  item, lf_item_t * fifo );
/*!
\~russian
\brief
Извлечение элемента из FIFO.

\warning Эта функция может "зависнуть" при использовании в прерываниях и в системах с вытесняющей многозадачностью.

\param item Указатель буфер для указателя на извлеченный элемент.
\param fifo Указатель на FIFO.
\return LF_ST_OK или код ошибки.
\~english
\brief
Extract an item from a FIFO.

\warning This function may deadlock if used in interrupt or in a preemptive multitasking system.

\param item An item buffer pointer.
\param fifo A FIFO pointer.
\return LF_ST_OK or error code.
*/
lf_st_t lf_item_get( lf_item_t ** item, lf_item_t * fifo ); //Get an item from lock-free fifo (MUST used by SINGLE thread only!!!)
//===============================================================================
void lf_item_init( lf_item_t * item )
{
    item->prev = item;
    item->next = item;
}
//===============================================================================
lf_st_t lf_item_put( lf_item_t * item, lf_item_t * fifo )
{
    //One itteration per interrupt on single processor.
    while(1)
    {
        //Many threads may call to lf_item_put( item, some_fifo)
        if( LF_CAS( item->prev, item, fifo->prev) )
        {
            //Item is locked, it's not in the fifo,, so may do this:
            item->next = fifo;
            //Many threads may call to lf_item_put( some_item, fifo) or lf_item_get( fifo)
            if( LF_CAS( fifo->prev, item->prev, item) )
            {
                break;//May do the rest.
            }
            else
            {
                item->next = item;
                //Unlock item;
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
//===============================================================================
lf_st_t lf_item_get( lf_item_t ** item, lf_item_t * fifo )
{
    //Check if fifo is empty
    //Some thread may write fifo->prev at the same time, so...
    while(1)
    {
        if( LF_CAS( fifo->prev, fifo, fifo) )
        {
            //Empty fifo
            *item = (lf_item_t *)0;
            return LF_ST_EEMPTY;
        }
        else
        {
            lf_item_t * head;
            head = fifo->prev;
            if( LF_CAS( fifo->next, head, head)  )
            {
                //Single item check 2
                if( LF_CAS( fifo->prev, head, fifo) )
                {
                    LF_DLCT_INIT();
                    //Successfully cut the only item
                    while( LF_CAS( fifo->next, fifo, fifo) )
                    {
                        //We have interrupted or working concurrent with
                        //lf_item_put( head, fifo ) call, we must wait;
                        if( LF_DLCT_FAIL() )
                        {
                            //Dead lock detected
                            *item = (lf_item_t *)0;
                            return LF_ST_EDLOCK;
                        }
                        LF_YELD();
                    }
                    //Now we can chenge fifo->next pointer.
                    LF_CAS( fifo->next, head, fifo);
                }
                else
                {
                    //Another thread have called lf_item_put( some_item, fifo ) or lf_item_get( fifo )
                    LF_YELD();
                    continue;
                }

            }
            else
            {
                LF_DLCT_INIT();
                //Multiple items
                while(1)
                {
                    head = fifo->next;
                    if( LF_CAS( head->next->prev, head, fifo) )
                    {
                        //Succefully cut the head, finish the job;
                        fifo->next = head->next;
                        //LF_CAS( fifo->next, head, head->next);
                        break;
                    }
                    else
                    {
                        //We have interrupted lf_item_put( head, fifo ) call, we must wait;
                        //for fifo->next->next chain to form, then cut the head!
                        if( LF_DLCT_FAIL() )
                        {
                            //Dead lock detected
                            *item = (lf_item_t *)0;
                            return LF_ST_EDLOCK;
                        }
                        LF_YELD();
                        continue;
                    }
                }
            }
            //Now we can handle head->next
            head->next = head;
            LF_CAS( head->prev, head->prev, head );//Unlock the head.

            *item = head;
            return LF_ST_OK;
        }
    }
}
//===============================================================================
lf_item_t tst_item[10];
lf_item_t tst_fifo;

int main()
{
    int i;

    lf_item_t * tst_ret;
    lf_st_t     tst_stat;

    //Disable warning!
    (void)tst_ret;
    (void)tst_stat;

    for( i = 0; i < 10; i++ )
    {
        lf_item_init( tst_item + i );
    }

    lf_item_init( &tst_fifo );

    tst_stat = lf_item_put( tst_item    , &tst_fifo );
    tst_stat = lf_item_put( tst_item + 1, &tst_fifo );
    tst_stat = lf_item_put( tst_item + 2, &tst_fifo );

    tst_stat = lf_item_get( &tst_ret, &tst_fifo );
    tst_stat = lf_item_get( &tst_ret, &tst_fifo );
    tst_stat = lf_item_get( &tst_ret, &tst_fifo );
    tst_stat = lf_item_get( &tst_ret, &tst_fifo );

    printf("Hello world!\n");
    return 0;
}

