/**************************************************************************
    BuguRTOS-0.3.x(Bugurt real time operating system)
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
#ifdef CONFIG_MP
    spin_init( &mutex->lock );
    spin_lock( &mutex->lock );
#endif //CONFIG_MP
    xlist_init( (xlist_t *)mutex );
    mutex->free = (bool_t)1;
#ifdef CONFIG_USE_HIGHEST_LOCKER
    mutex->prio = prio;
#endif // CONFIG_USE_HIGHEST_LOCKER
#ifdef CONFIG_MP
    spin_unlock( &mutex->lock );
#endif //CONFIG_MP
}

// К моменту вызова захвачена блокировка mutex-а, запрещены прерывания
bool_t _mutex_lock( mutex_t * mutex )
{
    bool_t ret;
    proc_t * proc;
#ifdef CONFIG_MP
    spin_lock( &mutex->lock );
#endif //CONFIG_MP
    ret = mutex->free;
    proc = current_proc();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif // CONFIG_MP
#ifdef CONFIG_USE_HIGHEST_LOCKER
    _proc_lres_inc( proc, mutex->prio );
#else // !CONFIG_USE_HIGHEST_LOCKER
    _proc_lres_inc( proc );
#endif // CONFIG_USE_HIGHEST_LOCKER
    if( ret )
    {
        mutex->free = (bool_t)0;
#ifdef CONFIG_USE_HIGHEST_LOCKER
        // Меняем приоритет только здесь
        _proc_prio_control_running( proc );
#endif // CONFIG_USE_HIGHEST_LOCKER
    }
    else
    {
        proc->flags |= PROC_FLG_QUEUE;
        proc->flags &= ~PROC_FLG_RUN;
        _proc_stop_( proc );
        gitem_insert( (gitem_t *)proc, (xlist_t *)mutex );
        // Нужна перепланировка
#ifdef CONFIG_MP
        resched( proc->core_id );
#else
        resched();
#endif // CONFIG_MP
    }
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
    spin_unlock( &mutex->lock );
#endif // CONFIG_MP
    return ret;
}

bool_t _mutex_try_lock( mutex_t * mutex )
{
    bool_t ret;
    proc_t * proc;
#ifdef CONFIG_MP
    spin_lock( &mutex->lock );
#endif //CONFIG_MP
    ret = mutex->free;
    proc = current_proc();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif // CONFIG_MP
    if( ret )
    {
        mutex->free = (bool_t)0;
#ifdef CONFIG_USE_HIGHEST_LOCKER
        _proc_lres_inc( proc, mutex->prio );
        _proc_prio_control_running( proc );
#else // CONFIG_USE_HIGHEST_LOCKER
        _proc_lres_inc( proc );
#endif // CONFIG_USE_HIGHEST_LOCKER
    }
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
    spin_unlock( &mutex->lock );
#endif // CONFIG_MP
    return ret;
}

void _mutex_unlock( mutex_t *  mutex )
{
    proc_t * proc;
#ifdef CONFIG_MP
    spin_lock( &mutex->lock );
#endif //CONFIG_MP
    proc = current_proc();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif // CONFIG_MP
#ifdef CONFIG_USE_HIGHEST_LOCKER
    _proc_lres_dec( proc, mutex->prio );
#else
    _proc_lres_dec( proc );
#endif // CONFIG_USE_HIGHEST_LOCKER
    // Если проготовлен и готов к остановке - останавливаем
    if(  ( proc->flags & PROC_FLG_PRE_END ) && (!(proc->flags & PROC_FLG_HOLD))  )
    {
        proc->flags &= ~(PROC_FLG_RUN|PROC_FLG_PRE_END);
        _proc_stop_( proc );
#ifdef CONFIG_USE_HIGHEST_LOCKER
        _proc_prio_control_stoped( proc );
#endif // CONFIG_USE_HIGHEST_LOCKER
        // Нужна перепланировка, процесс остановили и не запустили обратно
#ifdef CONFIG_MP
        resched( proc->core_id );
#else
        resched();
#endif // CONFIG_MP
    }
#ifdef CONFIG_USE_HIGHEST_LOCKER
    // Не останавливаем - меняем проиритет на ходу
    else _proc_prio_control_running( proc );
#endif // CONFIG_USE_HIGHEST_LOCKER
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif // CONFIG_MP
    // Обрабока самого мьютекса
    if( ((xlist_t *)mutex)->index == (index_t)0  )
    {
        // Список ожидающих пуст, выходим
        mutex->free = (bool_t)1;
#ifdef CONFIG_MP
        goto exit_label;
#else
        return;
#endif // CONFIG_MP
    }
    // Список ожидающих не пуст, запускаем голову
    proc = (proc_t *)xlist_head((xlist_t *)mutex);
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif // CONFIG_MP
    // Сначала надо вырезать
    proc->flags &= ~PROC_FLG_QUEUE;
    gitem_cut( (gitem_t *)proc );
#ifdef CONFIG_USE_HIGHEST_LOCKER
    // Меняем приоритет
    _proc_prio_control_stoped( proc );
#endif // CONFIG_USE_HIGHEST_LOCKER
    _proc_run( proc );
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
exit_label:
    spin_unlock( &mutex->lock );
#endif // CONFIG_MP
}