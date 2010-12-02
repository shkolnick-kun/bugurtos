/**************************************************************************
    BuguRTOS-0.0.x(nuTyx) a test code 4 BuguRTOS-0.x.x.
    Probably it won't B a real OS.
    Copyright (C) 2010  anonimous

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
/*
This logo was graciously delivered by 10003-kun ITT:
http://www.0chan.ru/r/res/9996.html
*/
#include <stdio.h>
#include <stdlib.h>
#include"src/include/bugurt.h"

int j = 0;
int i = 0xff;
void * retval;
void * retval_store;

//===========================================================================================
proc_t
    gp1,gp2,gp3,gp4,gp5,gp6,
    rt1,rt2,rt3,rt4,rt5,rt6;
//sem_t my_sem;
sig_t my_sig;

lock_t big_lock,run_lock;
unsigned int run = 1;
//======================================================================
void gp1f(void){
    printf("name:gp1,\t prio: %d,\t time2run: %d\n",gp1.prio,gp1.timer);
}
//======================================================================
void gp2f(void){
    printf("name:gp2,\t prio: %d,\t time2run: %d\n",gp2.prio,gp2.timer);
}
//======================================================================
void gp3f(void){
    printf("name:gp3,\t prio: %d,\t time2run: %d\n",gp3.prio,gp3.timer);
    proc_self_stop();
}
//======================================================================
//static count_t sem_count = 10, locked = 0;
static count_t sig_count = 10;
void gp4f(void){
/*
    if(sem_count==10){
        if(sem_lock( &my_sem )){
            locked++;
            printf(" V ");
        }else printf(" - ");
    }
*/
    if(!sig_count--){
        sig_count = 10;
        //sig_broadcast( &my_sig );
        sig_signal( &my_sig );
        printf(" =^_^= ");
    }
    printf("name:gp4,\t prio: %d,\t time2run: %d\n",gp4.prio,gp4.timer);
/*
    if(!sem_count--){
        sem_count = 10;
        if(locked){
            locked--;
            sem_unlock( &my_sem );
            printf(" A ");
        }
    }
*/
}
//======================================================================
static gp5_count = 2;
void gp5f(void){
    if(!gp5_count--){
        gp5_count = 2;
        sig_wait( &my_sig );
        printf(" x_x ");
    }
/*
    if( sem_lock( &my_sem ) ){
        sem_unlock( &my_sem );
        printf(" * ");
    }
*/
    printf("name:gp5,\t prio: %d,\t time2run: %d\n",gp5.prio,gp5.timer);
}
//======================================================================
static gp6_count = 2;
void gp6f(void){
/*
    if( sem_lock( &my_sem ) ){
        sem_unlock( &my_sem );
        printf(" * ");
    }
*/
    if(!gp6_count--){
        gp6_count = 2;
        sig_wait( &my_sig );
        printf(" x_x ");
    }
    printf("name:gp6,\t prio: %d,\t time2run: %d\n",gp6.prio,gp6.timer);
}
//===========================================================================================
void rt1f(void){
    printf("name:rt1,\t prio: %d,\t time2run: %d\n",rt1.prio,rt1.timer);
    proc_self_stop();
}
//======================================================================
static rt2_count = 2;
void rt2f(void){
/*
    if( sem_lock( &my_sem ) ){
        sem_unlock( &my_sem );
        printf(" * ");
    }
*/
    if(!rt2_count--){
        rt2_count = 2;
        sig_wait( &my_sig );
        printf(" x_x ");
    }
    printf("name:rt2,\t prio: %d,\t time2run: %d\n",rt2.prio,rt2.timer);
}
//======================================================================
static rt3_count = 2;
void rt3f(void){
/*
    if( sem_lock( &my_sem ) ){
        sem_unlock( &my_sem );
        printf(" * ");
    }
*/
    if(!rt3_count--){
        rt3_count = 2;
        sig_wait( &my_sig );
        printf(" x_x ");
    }
    printf("name:rt3,\t prio: %d,\t time2run: %d\n",rt3.prio,rt3.timer);
}
//======================================================================
void rt4f(void){
    printf("name:rt4,\t prio: %d,\t time2run: %d\n",rt4.prio,rt4.timer);
}
//======================================================================
void rt5f(void){
    printf("name:rt5,\t prio: %d,\t time2run: %d\n",rt5.prio,rt5.timer);
}
//======================================================================
void rt6f(void){
    printf("name:rt6,\t prio: %d,\t time2run: %d\n",rt6.prio,rt6.timer);
}

void stack_init(proc_t * proc){
    proc->stack_pointer = proc->stack_start;
}

bool_t _sem_try_lock(lock_t * lock){
    bool_t ret = 0;
    pthread_spin_lock( &big_lock );
    if(*lock){
        ret = 1;
        (*lock)--;
    }
    pthread_spin_unlock( &big_lock );
    return (ret);
}
void _sem_unlock(lock_t * lock){
    pthread_spin_lock( &big_lock );
    (*lock)++;
    pthread_spin_unlock( &big_lock );
}

void resched_local( void ){}
void resched_extern( sched_t * sched ){}
void resched_system(void){}

void spin_init(lock_t * lock){
    pthread_spin_init( lock,0 );
}

void spin_lock(lock_t * lock){
    pthread_spin_lock(lock);
}
void spin_unlock(lock_t * lock){
    for(int i = 0; i < 100000; i++);
    pthread_spin_unlock(lock);
}

load_t load_calc( sched_t * sched ){
    return sched->total_gp_quant + sched->proc_count_gp + sched->proc_count_rt + (sched->total_rt_quant>>2);
}

pthread_mutex_t start_mutex, console_mutex;
pthread_cond_t start_cond;
pthread_t local_thread, core0, core1;

//определить
sched_t * current_sched(void){
    pthread_t current_thread = pthread_self();
    if(current_thread==core1)return sched_array + 1;
    else return sched_array;
}

sched_t * _enter_crit_sec(void){return current_sched();}
void _enter_crit_sec_2(sched_t * sched){}
void _exit_crit_sec(sched_t * sched){}

static void * core1_func( void * arg ){
    int test, s=0;
    while(1){
        pthread_spin_lock( &run_lock );
        test = run;
        pthread_spin_unlock( &run_lock );
        if(!test){
            pthread_exit(arg);
            return;
        }

        pthread_mutex_lock( &start_mutex );
        pthread_cond_wait( &start_cond, &start_mutex );
        pthread_mutex_unlock( &start_mutex );

        printf("\ncore1: %d \t %d\t %d\t", ++s, sched_array[1].proc_count_gp, sched_array[1].proc_count_rt);
        sched_array[1].current_proc->code();
        schedule(&sched_array[1]);
    }
}

static void * core0_func( void * arg ){
    int test, s=0;
    while(1){
        pthread_spin_lock( &run_lock );
        test = run;
        pthread_spin_unlock( &run_lock );
        if(!test){
            pthread_exit(arg);
            return;
        }
        pthread_mutex_lock( &start_mutex );
        pthread_cond_wait( &start_cond, &start_mutex );
        pthread_mutex_unlock( &start_mutex );

        printf("\ncore0: %d \t %d\t %d\t", ++s, sched_array[0].proc_count_gp, sched_array[0].proc_count_rt);
        sched_array[0].current_proc->code();
        schedule(&sched_array[0]);
    }
    pthread_exit(arg);
}


void system_resched(void){}

static void * thread_func( void * arg ){
    printf("This is thread 1 %d\n", (int)*(int *)arg);
    printf("\n\r");
    pthread_exit((void *)&j);
}


//===========================================================================================
int main()
{
    pthread_create( &local_thread,0,thread_func, (void *)&i);

    pthread_join(local_thread, &retval_store);

    pthread_mutex_init( &start_mutex, 0);
    pthread_cond_init(&start_cond, 0);

    pthread_mutex_init( &console_mutex, 0);

    pthread_spin_init( &big_lock,0 );

    spin_init(&sched_index_lock);

    proc_init(&gp1,0,gp1f,3,0,1,1);
    proc_init(&gp2,0,gp2f,3,0,2,1);
    scheduler_init(&sched_array[0],&gp1);
    scheduler_init(&sched_array[1],&gp2);

    proc_init(&gp3,0,gp3f,1,0,3,2);
    proc_init(&gp4,0,gp4f,1,0,3,3);
    proc_init(&gp5,0,gp5f,1,0,3,4);
    proc_init(&gp6,0,gp6f,2,0,3,5);

    proc_init(&rt1,0,rt1f,1,1,2,6);
    proc_init(&rt2,0,rt2f,2,1,2,5);
    proc_init(&rt3,0,rt3f,3,1,2,4);
    proc_init(&rt4,0,rt4f,2,1,2,3);
    proc_init(&rt5,0,rt5f,3,1,2,2);
    proc_init(&rt6,0,rt6f,3,1,2,1);

    //sem_init( &my_sem, 1 );
    sig_init( &my_sig );
//    proc_run(&gp1);
//    proc_run(&gp2);
    proc_run(&gp3);
    proc_run(&gp4);
    proc_run(&gp5);
    proc_run(&gp6);

    proc_stop(&gp3);

    proc_run(&gp3);

    //gp1.affinity = 3;
    //gp2.affinity = 3;
    gp3.affinity = 3;
    gp4.affinity = 3;
    gp5.affinity = 3;

    proc_run(&rt1);
    proc_run(&rt2);
    proc_run(&rt3);
    proc_run(&rt4);
    proc_run(&rt5);
    proc_run(&rt6);

    proc_stop(&rt3);

    proc_run(&rt3);

    rt1.affinity = 3;
    rt2.affinity = 3;
    rt3.affinity = 3;
    rt4.affinity = 3;
    rt5.affinity = 3;

    run = 1;
    pthread_spin_init( &run_lock,0 );


    pthread_create( &core0,0,core0_func, (void *)&i);
    pthread_create( &core1,0,core1_func, (void *)&i);

/*
for(int i = 0; i < 100; i++){
    system_sched.current_proc->code();
    schedule(&system_sched);
}
rt1.timer = 7;
proc_run(&rt1);
for(int i = 0; i < 100; i++){
    system_sched.current_proc->code();
    schedule(&system_sched);
}
*/

    for(int s = 0; s < 900; s++){
        pthread_cond_broadcast( &start_cond );
        for(int d = 0; d < 20000000; d++);
    }
    rt1.timer = 7;
    rt2.timer = 8;
    rt3.timer = 9;
    rt4.timer = 10;
    rt5.timer = 11;
    rt6.timer = 12;
    proc_run(&rt1);
    proc_run(&rt2);
    proc_run(&rt3);
    proc_run(&rt4);
    proc_run(&rt5);
    proc_run(&rt6);
    for(int s = 0; s < 100; s++){
        pthread_cond_broadcast( &start_cond );
        for(int d = 0; d < 20000000; d++);
    }

    pthread_spin_lock( &run_lock );
    run = 0;
    pthread_spin_unlock( &run_lock );

    //for(int d = 0; d < 40000000; d++);

    pthread_cond_broadcast( &start_cond );

    pthread_join(core0, &retval_store);
    pthread_join(core1, &retval_store);

    printf("Preved \n");

    return 0;
}
