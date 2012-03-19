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
///========================================================================================
// Инициация
void sched_init(sched_t * sched, proc_t * idle)
{
#ifdef CONFIG_MP
    lock_t * sched_lock;
    sched_lock = &sched->lock;
    spin_init( sched_lock );
    spin_lock( sched_lock );
#endif // CONFIG_MP
    sched->ready = (xlist_t *)sched->plst;
    xlist_init( sched->ready );
    sched->expired = (xlist_t *)sched->plst + 1;
    xlist_init( sched->expired );
    gitem_insert( (gitem_t *)idle, sched->ready );
    sched->current_proc = idle;
    sched->nested_crit_sec = (count_t)0;//вообще это выполняется при запрещенных прерываниях, но не известно, на этом ли процессоре
#ifdef CONFIG_MP
    spin_unlock( sched_lock );
    stat_inc( idle, (stat_t *)kernel.stat + idle->core_id );
#endif // CONFIG_MP
}
static void _sched_list_switch( sched_t * sched )
{
    // Список ready опустел, переключаем списки
    if( sched->ready->index == (index_t)0 )
    {
        xlist_t * buf;
        buf = sched->ready;
        sched->ready = sched->expired;
        sched->expired = buf;
    }
}
/******************************************************************************************
Если у нас есть процессор и отвечающий за управление этим процессором объект типа sched_t,
то изменять поля current_proc, ready, expired мы будем только
с этого самого процессора во время вызовов функций sched_schedule sched_reschedule.

Отсюда правила использования этих функций:

1) Выполнение их должно быть атомарно (иначе будут гонки,
   между обработчиками прерываний системмного таймера и перепланирования).

2) В качестве аргумента передаем только тот объект, который управляет процессами
на исполняющем функции процессоре.
******************************************************************************************/
// Функция планирования, переключает процессы в обработчике системмного таймера
void sched_schedule(
#ifdef CONFIG_MP
                    sched_t * sched
#else
                    void
#endif // CONFIG_MP
                    )
{
    proc_t * current_proc;
#ifndef CONFIG_MP
    sched_t * sched;
    sched = (sched_t *)&kernel.sched;
#endif // nCONFIG_MP
    // Меняем только с локального процессора, блокировку sched->lock можно не захватывать!
    current_proc = sched->current_proc;
#ifdef CONFIG_MP
    // А вот эту блокировку обязательно надо захватить!
    spin_lock( &current_proc->lock );
#endif // CONFIG_MP
    // Хук "сохранение контекста"
    if( current_proc->sv_hook )current_proc->sv_hook( current_proc->arg );
    // Проверяем, что процесс находится в списке ready
    if( (xlist_t *)((gitem_t *)current_proc)->group->link == sched->ready )
    {
        // Переключаем cписок на следующий за текущим процесс
#ifdef CONFIG_MP
        spin_lock( &sched->lock );
#endif // CONFIG_MP
        xlist_switch( sched->ready, ((gitem_t *)current_proc)->group->prio );
#ifdef CONFIG_MP
        spin_unlock( &sched->lock );
#endif // CONFIG_MP
        //Проверяем, не истек ли квант времени процесса
        if( current_proc->timer > (timer_t)1 )current_proc->timer--;// Не истек, уменьшаем таймер
        else
        {
            flag_t flags;
            // Истек, вырезаем процесс из списка
#ifdef CONFIG_MP
            spin_lock( &sched->lock );
#endif // CONFIG_MP
            gitem_fast_cut( (gitem_t *)current_proc );
#ifdef CONFIG_MP
            spin_unlock( &sched->lock );
#ifdef CONFIG_USE_ALB
            spin_lock( &kernel.stat_lock );
            // Обновили статистику после удаления процесса из списка ready
            stat_dec( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
#endif // CONFIG_USE_ALB
#endif // CONFIG_MP
            // А что за процесс собственно?
            flags = current_proc->flags;
            if(
                (!(flags & PROC_FLG_RT))
#ifndef CONFIG_HARD_RT
                ||(flags & PROC_FLG_HOLD)
#endif // CONFIG_HARD_RT
            )
            {
                //Процесс общего назначения, либо он удерживает общий ресурс, переносим в очередь expired и сбрасываем таймер
#if defined(CONFIG_MP) && defined(CONFIG_USE_ALB)
                sched_t * new_sched;
                // Балансировка нагрузки
                current_proc->core_id = sched_load_balancer( current_proc, (stat_t *)kernel.stat );
                // Получаем указатель на новый планиировщик
                new_sched = (sched_t *)kernel.sched + current_proc->core_id;
                // Обновляем нагрузку на новом ядре
                stat_inc( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
                spin_unlock( &kernel.stat_lock );

                // Вставляем процесс в список  expired
                spin_lock( &new_sched->lock );
                gitem_insert( (gitem_t *)current_proc, new_sched->expired );
                spin_unlock( &new_sched->lock );
#else // CONFIG_MP CONFIG_USE_ALB
                // Тупо переносим процесс в список expired
#ifdef CONFIG_MP
                spin_lock( &sched->lock );
#endif // CONFIG_MP
                gitem_insert( (gitem_t *)current_proc, sched->expired );
#ifdef CONFIG_MP
                spin_unlock( &sched->lock );
#endif // CONFIG_MP

#endif // CONFIG_MP CONFIG_USE_ALB
                current_proc->timer = current_proc->time_quant; // Сбросили таймер!
            }
            else
            {
                // Процесс жесткого реального времени без захваченных ресурсов, тупо снимаем с выполнения, watchdog надо было сбрасыввать
#ifdef CONFIG_MP
#ifndef CONFIG_USE_ALB
                // Обновили статистику после удаления процесса из списка ready
                spin_lock( &kernel.stat_lock );
                stat_dec( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
#endif // nCONFIG_USE_ALB
                spin_unlock( &kernel.stat_lock );
#endif // CONFIG_MP
                ((gitem_t *)current_proc)->group->link = (void *)0;// Просто вырезали из списка, как в gitem_cut
                current_proc->flags |= PROC_FLG_WD_STOP;//Остановлен по WD
                current_proc->flags &= ~PROC_FLG_RUN;
            }
        }
    }
#ifdef CONFIG_MP
    //Текущий процесс более не нужен, освобождаем его блокировку
    spin_unlock( &current_proc->lock );
    spin_lock( &sched->lock );
#endif // CONFIG_MP
    _sched_list_switch( sched );
    // Изменять указатель будем при захваченной блокировке,
    // чтобы процессы на других процессорах не прочитали неизвестно что.
    current_proc = (proc_t *)xlist_head( sched->ready ); // Вытесняющая многозадачность же!
    sched->current_proc = current_proc;
#ifdef CONFIG_MP
    spin_unlock( &sched->lock );
    spin_lock( &current_proc->lock );
#endif // CONFIG_MP
    //Хук "восстановление контекста"
    if( current_proc->rs_hook )current_proc->rs_hook( current_proc->arg );
#ifdef CONFIG_MP
    spin_unlock( &current_proc->lock );
#endif // CONFIG_MP
}
//----------------------------------------------------------------------------------------
// Функция перепланирования, переключает процессы в обработчике прерывания resched
void sched_reschedule(
#ifdef CONFIG_MP
                        sched_t * sched
#else
                        void
#endif // CONFIG_MP
                       )
{
    proc_t * current_proc;
#ifndef CONFIG_MP
    sched_t * sched;
    sched = (sched_t *)&kernel.sched;
#endif // nCONFIG_MP
    // Меняем только с локального процессора, блокировку sched->lock можно не захватывать!
    current_proc = sched->current_proc;
#ifdef CONFIG_MP
    // А вот эту блокировку обязательно надо захватить!
    spin_lock( &current_proc->lock );
#endif // CONFIG_MP
    // Хук "сохранение контекста"
    if( current_proc->sv_hook )current_proc->sv_hook( current_proc->arg );
#ifdef CONFIG_MP
    spin_unlock( &current_proc->lock );
    spin_lock( &sched->lock );
#endif // CONFIG_MP
    _sched_list_switch( sched );
    current_proc = (proc_t *)xlist_head( sched->ready ); // Вытесняющая многозадачность же!
    sched->current_proc = current_proc;
#ifdef CONFIG_MP
    spin_unlock( &sched->lock );
#endif // CONFIG_MP

#ifdef CONFIG_MP
    spin_lock(&current_proc->lock);
#endif // CONFIG_MP
    //Хук "восстановление контекста"
    if( current_proc->rs_hook )current_proc->rs_hook( current_proc->arg );
#ifdef CONFIG_MP
    spin_unlock( &current_proc->lock );
#endif // CONFIG_MP
}
#ifdef CONFIG_MP
//========================================================================================
// Балансировщик нагрузки
core_id_t sched_load_balancer(proc_t * proc, stat_t * stat)
{
    core_id_t core = (core_id_t)0, ret;
    affinity_t mask = (affinity_t)1;
    while( core < (core_id_t)MAX_CORES )
    {
        if( proc->affinity & mask )break;
        mask<<=1;
        core++;
    }
    // Начальное предположение
    stat += (core_id_t)core;
    ret = core++;
    mask<<=1;
    {
        prio_t proc_prio;
        load_t current_load, min_load;

        proc_prio = ((gitem_t *)proc)->group->prio;
        min_load = stat_calc_load( proc_prio, stat++ );
        // Проверка всего остального, тупой поиск минимума
        while( core < (core_id_t)MAX_CORES )
        {
            current_load = stat_calc_load( proc_prio, stat++ );
            if( (proc->affinity & mask) && (current_load < min_load) )
            {
                min_load = current_load;
                ret = core;
            }
            mask<<=1;
            core++;
        }
    }
    return ret;
}
//----------------------------------------------------------------------------------------
//Поиск самой нагруженной структуры stat_t в массиве
core_id_t sched_highest_load_core( stat_t * stat )
{
    // Начальное предположение
    load_t max_load;
    core_id_t object_core = (core_id_t)0; //процессор с максимальной нагрузкой, с которого эту нагрузку будем снимать
    core_id_t core = (core_id_t)1;
    max_load  = stat_calc_load( (prio_t)BITS_IN_INDEX_T, stat ); // максимальная нагрузка

    while( core < (core_id_t)MAX_CORES )
    {
        load_t current_load;
        current_load = stat_calc_load( (prio_t)BITS_IN_INDEX_T, stat + core );
        if( current_load > max_load )
        {
            max_load = current_load;
            object_core = core;
        }
        core++;
    }

    return object_core;
}
#endif // CONFIG_MP
