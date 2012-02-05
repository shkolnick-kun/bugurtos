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
void proc_init(
    proc_t * proc, //Указатель на инициируемый процесс
    code_t pmain,
    code_t sv_hook,
    code_t rs_hook,
    void * arg,
    stack_t *sstart,
    prio_t prio,
    timer_t time_quant,
    bool_t is_rt // если true, значит процесс будет иметть поведение RT
#ifdef CONFIG_MP
    ,affinity_t affinity
#endif // CONFIG_MP
)
{
    ENTER_CRIT_SEC();
    proc_init_isr(
                    proc, //Указатель на инициируемый процесс
                    pmain,
                    sv_hook,
                    rs_hook,
                    arg,
                    sstart,
                    prio,
                    time_quant,
                    is_rt // если true, значит процесс будет иметть поведение RT
#ifdef CONFIG_MP
                    ,affinity
#endif // CONFIG_MP
                );
    EXIT_CRIT_SEC();
}

//Обертка для запуска процессса
void proc_run_wrapper(proc_t * proc)
{
    //Атомарно читаем pmain и arg
    disable_interrupts();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif // CONFIG_MP
    code_t pmain = proc->pmain;
    void * arg = proc->arg;
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif // CONFIG_MP
    enable_interrupts();
    //Выполняем pmain
    pmain( arg );
    //Завершаем работу процесса
    disable_interrupts();
    _proc_terminate_isr(proc);
    enable_interrupts();
}

// Функция общего пользования - запуск процесса
bool_t proc_run(proc_t * proc)
{

    ENTER_CRIT_SEC();
    bool_t ret = proc_run_isr( proc );
    EXIT_CRIT_SEC();
    return ret;
}

// Перезепуск процесса
bool_t proc_restart(proc_t * proc)
{
    ENTER_CRIT_SEC();
    bool_t ret = proc_restart_isr( proc );
    EXIT_CRIT_SEC();
    return ret;
}

// Останов процесса
bool_t proc_stop( proc_t * proc )
{
    ENTER_CRIT_SEC();
    bool_t ret = proc_stop_isr( proc );
    EXIT_CRIT_SEC();
    return ret;
}

void proc_reset_watchdog(void)
{
    proc_t * proc;
#ifdef CONFIG_MP
    core_id_t current_core = _enter_crit_sec();
    proc = ((sched_t *)kernel.sched + current_core)->current_proc;
    spin_lock(&proc->lock);
#else
    enter_crit_sec();
    proc = kernel.sched.current_proc;
#endif
    if( proc->flags & PROC_FLG_RT )proc->timer = proc->time_quant;
#ifdef CONFIG_MP
    spin_lock(&proc->lock);
    _exit_crit_sec(current_core);
#else
    exit_crit_sec();
#endif
}

// самоостанов процесса по флагам
void proc_flag_stop( flag_t mask )
{
    disable_interrupts();
    _proc_flag_stop_isr( mask );
    enable_interrupts();
}
// самоостанов процесса
void proc_self_stop(void)
{
#ifdef CONFIG_MP
    core_id_t current_core = _enter_crit_sec();
    proc_t * proc = ((sched_t *)kernel.sched + current_core)->current_proc;
    spin_lock( &proc->lock );
#else
    enter_crit_sec();
    proc_t * proc = kernel.sched.current_proc;
#endif // CONFIG_MP
    _proc_stop( proc );
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
    _exit_crit_sec( current_core );
#else
    exit_crit_sec();
#endif // CONFIG_MP
}

#if defined(CONFIG_MP) && (!defined(CONFIG_USE_ALB))
/************************************
  "Ленивые" балансировщики нагрузки

,предназначены для запуска из тел
процессов, если не используется
активная схема балансировки нагрузки.

Можно использовать только один,
или оба в различных комбинациях

************************************/
// Локальный
void proc_lazy_local_load_balancer(void)
{
    core_id_t current_core = _enter_crit_sec();
    _proc_lazy_load_balancer( current_core );
    _exit_crit_sec( current_core );
}
// Глобальный
void proc_lazy_global_load_balancer(void)
{
    core_id_t current_core = _enter_crit_sec();
    _proc_global_lazy_load_balancer();
    _exit_crit_sec( current_core );
}
#endif // CONFIG_MP CONFIG_USE_ALB
