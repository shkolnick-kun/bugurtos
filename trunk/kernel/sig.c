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
//========================================================================================
// Инициация
void sig_init_isr( sig_t * sig )
{
#ifdef CONFIG_MP
    core_id_t i;
    SPIN_INIT( sig );
    SPIN_LOCK( sig );

    for( i = 0; i < (core_id_t)MAX_CORES; i++ )
    {
        xlist_init( (xlist_t *)sig->sig_list + i );
        stat_init( (stat_t *)sig->sig_stat + i );
    }
    SPIN_UNLOCK( sig );
#else
    xlist_init( (xlist_t *)sig );
#endif
}
//========================================================================================
// Это выполнится при постановке процесса в список ожидания сигнала
void _sig_wait_prologue( sig_t * sig )
{
    proc_t * proc;

    SPIN_LOCK( sig );

    proc = current_proc();

    SPIN_LOCK( proc );

    // Останавливаем процесс
    _proc_stop_flags_set( proc, PROC_STATE_W_SIG );
    // Вставляем процесс в группированный список ожидания сигнала
#ifdef CONFIG_MP
    {
        /*
        Балансировка нагрузки производится заранее,
        в этом случае получается сделать sig_broadcast  с временем выполнения O(1),
        однако про hotplug  придется забыть, ну и ладно.
        */
        core_id_t sig_core;
        sig_core = sched_load_balancer( proc, (stat_t *)sig->sig_stat );

        proc->core_id = sig_core;
        pitem_insert((pitem_t *)proc, (xlist_t *)sig + sig_core);
        stat_inc( proc, (stat_t *)sig->sig_stat + sig_core );
    }
#else
    pitem_insert( (pitem_t *)proc, (xlist_t *)sig );
#endif //CONFIG_MP
    SPIN_UNLOCK( proc );

    SPIN_UNLOCK( sig );
}
//========================================================================================
//
static void _sig_set_wakeup_flags( proc_t * proc )
{
    proc->flags &= PROC_STATE_CLEAR_MASK;
    proc->flags |= PROC_STATE_W_READY;
}
static void _sig_wakeup_list_proc( proc_t * proc )
{
    SPIN_LOCK( proc );

    proc->buf = ((item_t *)proc)->next;
    item_cut( (item_t *)proc );                  // Вырезать процесс из простого списка гораздо проще, чем из xlist
    _sig_set_wakeup_flags( proc );
    __proc_run( proc );

    SPIN_UNLOCK( proc );
}

void _sig_wait_epilogue( void )
{
    proc_t * proc;
    proc_t * wakeup_proc;
    proc = current_proc();

    SPIN_LOCK( proc );

    proc->flags &= PROC_STATE_CLEAR_MASK;
    proc->flags |= PROC_STATE_RUNNING;

    wakeup_proc = (proc_t *)proc->buf;
    proc->buf = (void *)0;

    SPIN_UNLOCK( proc );

    KERNEL_PREEMPT(); /// KERNEL_PREEMPT
    // Надо разбудить следующий процесс в списке.
    if( wakeup_proc )
    {
        // Если есть другие процессы для пробуждения, то "будим" самый приоритетный из них, он продолжит "побудку".
        if( wakeup_proc != proc )
        {
            //Нельзя будить себя! Будим только другой процесс!
            _sig_wakeup_list_proc( wakeup_proc );
        }
    }
}
//========================================================================================
// Будит 1 процесс, для вызова из обработчиков прерываний
void sig_signal_isr( sig_t * sig )
{
#ifdef CONFIG_MP
    core_id_t core;
    proc_t * proc;
    // Поиск процесса для запуска
    SPIN_LOCK( sig );// Захват блокировки сигнала
    // Находим самую нагруженную  структуру stat_t в сигнале
    core = sched_highest_load_core( (stat_t *)sig->sig_stat );
    // Этот процесс мы будем запускать
    {
        xlist_t * sig_list;
        sig_list = (xlist_t *)sig->sig_list + core;
        if(sig_list->index == (index_t)0)
        {
            SPIN_UNLOCK( sig );
            return;
        }
        proc = (proc_t *)xlist_head( sig_list );
    }
    SPIN_LOCK( proc );// Захват блокировки процесса
    // Вырезаем процесс из списка ожидания сигнала
    pitem_fast_cut( (pitem_t *)proc );
    stat_dec( proc, (stat_t *)sig->sig_stat + core );
    //Запуск процесса
    _sig_set_wakeup_flags( proc );
    // Вставляем его в список ready соответствующего планировщика
    spin_lock( &kernel.stat_lock );
    stat_inc( proc, (stat_t *)kernel.stat + core ); // Обновление статистики
    spin_unlock( &kernel.stat_lock );
    {
        sched_t * sched;
        sched = kernel.sched + core;// Дада, нагрузка была сбалансирована на этапе постановки в список ожидания
        SPIN_LOCK( sched );
        pitem_insert((pitem_t *)proc, sched->ready );
        SPIN_UNLOCK( sched );
    }
    resched(core);// Перепланировка
    SPIN_UNLOCK( proc );// Освобождение блокировки процесса
    SPIN_UNLOCK( sig );// Освобождение блокировки сигнала
#else
    proc_t * proc;
    if( ((xlist_t *)sig)->index == (index_t)0 )return;
    proc = (proc_t *)xlist_head( (xlist_t *)sig );
    pitem_fast_cut( (pitem_t *)proc );
    _sig_set_wakeup_flags( proc );
    pitem_insert( (pitem_t *)proc, kernel.sched.ready );
    resched();
#endif //CONFIG_MP
}
//----------------------------------------------------------------------------------------
// Будит все ожидающие процессы
void sig_broadcast_isr( sig_t * sig )
{
#ifdef CONFIG_MP
    core_id_t core;

    for(core = 0; core < (core_id_t)MAX_CORES; core++)
    {
        proc_t * wakeup_proc;

        SPIN_LOCK( sig );
        /*
        Фактически процессы еще не поставлены на выполнение,
        но обязательно будут, это надо учитывать при баланисировке нагрузки.
        */
        spin_lock( &kernel.stat_lock );

        stat_merge( (stat_t *)sig->sig_stat + core, (stat_t *)kernel.stat + core );

        spin_unlock( &kernel.stat_lock );
        /*
        Сцепляем список и будим его голову.
        */
        wakeup_proc = (proc_t *)pitem_xlist_chain( (xlist_t *)sig + core );
        if( wakeup_proc )
        {
            _sig_wakeup_list_proc( wakeup_proc );
        }

        resched(core);

        SPIN_UNLOCK( sig );

        KERNEL_PREEMPT(); /// KERNEL_PREEMPT
    }
#else
    proc_t * wakeup_proc;
    /*
    Сцепляем список и будим его голову.
    */
    wakeup_proc = (proc_t *)pitem_xlist_chain( (xlist_t *)sig );
    if( wakeup_proc )
    {
        _sig_wakeup_list_proc( wakeup_proc );
    }

    resched();
#endif //CONFIG_MP
}

