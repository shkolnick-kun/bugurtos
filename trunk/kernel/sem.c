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

// Инициализация
void sem_init_isr( sem_t * sem, count_t count )
{
#ifdef CONFIG_MP
    spin_init( &sem->lock );
    spin_lock( &sem->lock );
#endif //CONFIG_MP
    xlist_init( (xlist_t *)sem );
    sem->counter = count;
#ifdef CONFIG_MP
    spin_unlock( &sem->lock );
#endif //CONFIG_MP
}

// То же, для внутреннего использования
bool_t _sem_lock( sem_t * sem )
{
#ifdef CONFIG_MP
    spin_lock( &sem->lock );// Захват спин-блокировки семафора
#endif //CONFIG_MP
    bool_t ret = 0;
    if( sem->counter != 0 )
    {
        sem->counter--;
        ret = (bool_t)1;
    }
    else
    {
        proc_t * proc = current_proc();
#ifdef CONFIG_MP
        spin_lock( &proc->lock );// Захват блокировки процесса
#endif //CONFIG_MP
        proc->flags |= PROC_FLG_QUEUE;
        _proc_stop( proc );
        gitem_insert( (gitem_t *)proc, (xlist_t *)sem );
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );// Освобождение блокировки процесса
#endif //CONFIG_MP
    }
#ifdef CONFIG_MP
    spin_unlock( &sem->lock );// Освобождение спин-блокировки семафора
#endif //CONFIG_MP
    return ret;
}

// То же, для внутреннего использования
bool_t _sem_try_lock( sem_t * sem )
{
#ifdef CONFIG_MP
    spin_lock( &sem->lock );// Захват спин-блокировки семафора
#endif //CONFIG_MP
    bool_t ret = 0;
    if( sem->counter != 0 )
    {
        sem->counter--;
        ret = (bool_t)1;
    }
#ifdef CONFIG_MP
    spin_unlock( &sem->lock );// Освобождение спин-блокировки семафора
#endif //CONFIG_MP
    return ret;
}

void _sem_unlock( sem_t * sem )
{
    if( ((xlist_t *)sem)->index == (index_t)0  )
    {
        sem->counter++;
        return;
    }
    proc_t * proc = (proc_t *)xlist_head((xlist_t *)sem);
#ifdef CONFIG_MP
    spin_lock( &proc->lock );// Захват спин-блокировки процесса
#endif //CONFIG_MP
    proc->flags &= ~PROC_FLG_QUEUE;
    gitem_cut( (gitem_t *)proc );
    _proc_run( proc );
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );// Освобождение спин-блокировки процесса
#endif //CONFIG_MP
}

void sem_unlock_isr( sem_t * sem )
{
#ifdef CONFIG_MP
    spin_lock( &sem->lock );//Захват спин-блокировки семафора
#endif //CONFIG_MP
    _sem_unlock( sem );
#ifdef CONFIG_MP
    spin_unlock( &sem->lock );//Освобождение спин-блокировки семафора
#endif //CONFIG_MP
}
