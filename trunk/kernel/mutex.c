/**************************************************************************
    BuguRTOS-0.4.x(Bugurt real time operating system)
    Copyright (C) 2011  anonimous

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
#include "../include/bugurt.h"

void mutex_init_isr(
    mutex_t * mutex
#ifdef CONFIG_USE_HIGHEST_LOCKER
    ,prio_t prio
#endif // CONFIG_USE_HIGHEST_LOCKER
)
{
    SPIN_INIT( mutex );
    SPIN_LOCK( mutex );
    xlist_init( (xlist_t *)mutex );
    mutex->free = (bool_t)1;
#ifdef CONFIG_USE_HIGHEST_LOCKER
    mutex->prio = prio;
#endif // CONFIG_USE_HIGHEST_LOCKER
    SPIN_UNLOCK( mutex );
}

// К моменту вызова захвачена блокировка mutex-а, запрещены прерывания
bool_t _mutex_lock( mutex_t * mutex )
{
    bool_t ret;
    proc_t * proc;
    // Захват блокировки мьютекса
    SPIN_LOCK( mutex );
    ret = mutex->free;
    proc = current_proc();
    // Захват блокировки процесса
    SPIN_LOCK( proc );
    PROC_LRES_INC( proc, GET_PRIO( mutex ) );

    if( ret )
    {
        mutex->free = (bool_t)0;
        PROC_PRIO_CONTROL_RUNNING( proc );
    }
    else
    {
        proc->flags |= PROC_FLG_QUEUE;
        _proc_stop( proc );
        pitem_insert( (pitem_t *)proc, (xlist_t *)mutex );
    }
    SPIN_UNLOCK( proc );
    SPIN_UNLOCK( mutex );
    return ret;
}

bool_t _mutex_try_lock( mutex_t * mutex )
{
    bool_t ret;
    proc_t * proc;

    SPIN_LOCK( mutex );
    ret = mutex->free;
    proc = current_proc();

    SPIN_LOCK( proc );
    if( ret )
    {
        mutex->free = (bool_t)0;
        PROC_LRES_INC( proc, GET_PRIO( mutex ) );
        PROC_PRIO_CONTROL_RUNNING( proc );
    }
    SPIN_UNLOCK( proc );
    SPIN_UNLOCK( mutex );
    return ret;
}

void _mutex_unlock( mutex_t *  mutex )
{
    proc_t * proc;

    SPIN_LOCK( mutex );
    proc = current_proc();

    SPIN_LOCK(proc);
    PROC_LRES_DEC( proc, GET_PRIO( mutex ) );
    // Если проготовлен и готов к остановке - останавливаем
    if(  PROC_PRE_STOP_TEST(proc)  )
    {
        proc->flags &= ~PROC_FLG_PRE_STOP_MASK;
        _proc_stop_( proc );
        PROC_PRIO_CONTROL_STOPED( proc );
        // Нужна перепланировка, процесс остановили и не запустили обратно
        RESCHED_PROC( proc );
    }
    else
    {
        // Не останавливаем - меняем проиритет на ходу
        PROC_PRIO_CONTROL_RUNNING( proc );
    }
    SPIN_UNLOCK( proc );
    // Обрабока самого мьютекса
    if( ((xlist_t *)mutex)->index == (index_t)0  )
    {
        // Список ожидающих пуст, выходим
        mutex->free = (bool_t)1;
        goto end;
    }
    // Список ожидающих не пуст, запускаем голову
    proc = (proc_t *)xlist_head( (xlist_t *)mutex );
    SPIN_LOCK( proc );
    // Сначала надо вырезать
    pitem_cut( (pitem_t *)proc );
    proc->flags &= ~PROC_FLG_QUEUE;
    // Управление приоритетом процесса
    PROC_PRIO_CONTROL_STOPED( proc );
    _proc_run( proc );
    SPIN_UNLOCK( proc );
end:
    SPIN_UNLOCK( mutex );
}
