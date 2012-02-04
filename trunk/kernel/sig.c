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
//========================================================================================
// Инициация
void sig_init_isr( sig_t * sig )
{
#ifdef CONFIG_MP
    spin_init( &sig->lock );
    spin_lock( &sig->lock );
    core_id_t i;
    for( i = 0; i < (core_id_t)MAX_CORES; i++ )
    {
        xlist_init( (xlist_t *)sig->sig_list + i );
        stat_init( (stat_t *)sig->sig_stat + i );
    }
    spin_unlock( &sig->lock );
#else
    xlist_init( (xlist_t *)sig );
#endif
}
//========================================================================================
// Это выполнится при постановке процесса в список ожидания сигнала
void sig_wait_stage_1_isr( sig_t * sig )
{
#ifdef CONFIG_MP
    spin_lock( &sig->lock );
#endif // CONFIG_MP
    proc_t * proc = current_proc();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif // CONFIG_MP
    // Останавливаем процесс
    proc->flags |= PROC_FLG_WAIT;
    _proc_stop_( proc );
#ifdef CONFIG_MP
    resched( proc->core_id );
#else
    resched();
#endif // CONFIG_MP
    // Вставляем процесс в группированный список ожидания сигнала
#ifdef CONFIG_MP
    {
        /*
        Балансировка нагрузки производится заранее,
        в этом случае получается сделать sig_broadcast  с временем выполнения O(1),
        однако про hotplug  придется забыть, ну и ладно.
        */
        core_id_t sig_core = sched_load_balancer( proc, (stat_t *)sig->sig_stat );

        proc->core_id = sig_core;
        gitem_insert_group((gitem_t *)proc, (xlist_t *)sig + sig_core);
        stat_inc( proc, (stat_t *)sig->sig_stat + sig_core );
    }
    spin_unlock( &proc->lock );
    spin_unlock( &sig->lock );
#else
    gitem_insert_group( (gitem_t *)proc, (xlist_t *)sig );
#endif //CONFIG_MP
}
//========================================================================================
// Тоже самое что и предыдущие, олько для вызова из обработчиков прерываний и из критических секций
void sig_signal_isr( sig_t * sig )
{
#ifdef CONFIG_MP
    // Поиск процесса для запуска
    spin_lock( &sig->lock );// Захват блокировки сигнала
    // Находим самую нагруженную  структуру stat_t в сигнале
    core_id_t core = sched_highest_load_core( (stat_t *)sig->sig_stat );
    proc_t * proc;
    // Этот процесс мы будем запускать
    {
        xlist_t * sig_list = (xlist_t *)sig->sig_list + core;
        if(sig_list->index == (index_t)0)
        {
            spin_unlock( &sig->lock );
            return;
        }
        proc = (proc_t *)xlist_head( sig_list );
    }
    spin_lock( &proc->lock );// Захват блокировки процесса
    // Вырезаем процесс из списка ожидания сигнала
    gitem_fast_cut( (gitem_t *)proc );
    stat_dec( proc, (stat_t *)sig->sig_stat + core );
    //Запуск процесса
    // Вставляем его в список ready соответствующего планировщика
    spin_lock( &kernel.stat_lock );
    stat_inc( proc, (stat_t *)kernel.stat + core ); // Обновление статистики
    spin_unlock( &kernel.stat_lock );
    {
        sched_t * sched = kernel.sched + core;// Дада, нагрузка была сбалансирована на этапе постановки в список ожидания
        spin_lock( &sched->lock );
        gitem_insert((gitem_t *)proc, sched->ready );
        spin_unlock( &sched->lock );
    }
    resched(core);// Перепланировка
    spin_unlock( &proc->lock );// Освобождение блокировки процесса
    spin_unlock( &sig->lock );// Освобождение блокировки сигнала
#else
    if( ((xlist_t *)sig)->index == (index_t)0 )return;
    proc_t * proc = (proc_t *)xlist_head( (xlist_t *)sig );
    gitem_fast_cut( (gitem_t *)proc );
    gitem_insert( (gitem_t *)proc, kernel.sched.ready );
    resched();
#endif //CONFIG_MP
}
//----------------------------------------------------------------------------------------
void sig_broadcast_isr( sig_t * sig )
{
#ifdef CONFIG_MP
    core_id_t core;
    spin_lock( &sig->lock );
    for(core = 0; core < (core_id_t)MAX_CORES; core++)
    {
        spin_lock( &kernel.sched[core].lock );
        gitem_xlist_merge( (xlist_t *)sig + core, kernel.sched[core].ready );
        spin_unlock( &kernel.sched[core].lock );

        spin_lock( &kernel.stat_lock );
        stat_merge( (stat_t *)sig->sig_stat + core, (stat_t *)kernel.stat + core );
        spin_unlock( &kernel.stat_lock );

        resched(core);
    }
    spin_unlock( &sig->lock );
#else
    gitem_xlist_merge( (xlist_t *)sig, kernel.sched.ready );
    resched();
#endif //CONFIG_MP
}

