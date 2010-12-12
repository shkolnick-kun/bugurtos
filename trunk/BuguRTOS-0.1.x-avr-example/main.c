/**************************************************************************
    BuguRTOS-0.1.x(sguschekka) a small OS 4 microcontrollers.
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
/*!
 \example main.c
 \brief example main 4 avr
*/
#include <bugurt.h>

// Here are my processes, LOL.
proc_t gp01, gp02, gp03, gp11, gp12;
proc_t rt01, rt02, rt03, rt11, rt12, rt21;
// Static stack space allocation
stack_t sgp01[128], sgp02[128], sgp03[128], sgp11[128], sgp12[128];
stack_t srt01[128], srt02[128], srt03[128], srt11[128], srt12[128], srt21[128];

sem_t my_sem;
sig_t my_sig,my_sig2;

void gp01_main(void){
    while(1){
        sem_lock(&my_sem);
        update_system_timer();
        sem_unlock(&my_sem);
    }
}

void gp02_main(void){
    while(1){
        sem_lock(&my_sem);
        update_system_timer();
        sem_unlock(&my_sem);
    }
}

void gp03_main(void){
    while(1){
        wait_time(1);
        sig_wait(&my_sig);
    }
}

void gp11_main(void){
    while(1){
        wait_time(1);
        sig_wait(&my_sig);
    }
}

timer_t rt01_timer;
void gp12_main(void){
    timer_t blink;
    update_system_timer();
    CLEAR_TIMER(blink);
    CLEAR_TIMER(rt01_timer);
    while(1){
        update_system_timer();
        if(TIMER(blink)>500){
            CLEAR_TIMER(blink);
            CLEAR_TIMER(rt01_timer);
            sem_lock(&my_sem);
            proc_run(&rt01); // lol rt01 is going 2 B locked
            wait_time(1);
            sem_unlock(&my_sem);
            sig_broadcast(&my_sig);
        }
    }
}

void rt01_main(void){
    CLEAR_TIMER(rt01_timer);
    while(1){
        sem_lock(&my_sem);
        update_system_timer();
        proc_reset_watchdog();
        sem_unlock(&my_sem);
        if(TIMER(rt01_timer)>1){
            CLEAR_TIMER(rt01_timer);
            //proc_self_stop();
            proc_stop(&rt01);
        }
    }
}

void rt02_main(void){
    while(1){
        wait_time(1);
        proc_reset_watchdog();
        sig_wait(&my_sig);
    }
}

void rt03_main(void){
    while(1){
        wait_time(1);
        proc_reset_watchdog();
        sig_wait(&my_sig);
    }
}

void rt11_main(void){
    while(1){
        wait_time(1);
        proc_reset_watchdog();
        sig_wait(&my_sig2);
    }
}

void rt12_main(void){
    while(1){
        wait_time(1);
        proc_reset_watchdog();
        sig_wait(&my_sig2);
    }
}

void rt21_main(void){
    while(1){
        sem_lock(&my_sem);
        proc_reset_watchdog();
        sem_unlock(&my_sem);
        proc_self_stop();
    }
}

int main(void)
{
    init_bugurt();

    TCCR1A = 0x00;
    TCCR1B = 0x1d;
    OCR1A  = 4*2;
    OCR1B  = 0x00;
    TIFR = 0x00;
    ASSR   = 0x00;
    DDRB = 0xff;
    DDRC = 0xff;
    TIMSK = 0x10;

    // ololo
    proc_init(&gp01,&sgp01[127],gp01_main,0,0,3);
    proc_init(&gp02,&sgp02[127],gp02_main,0,0,2);
    proc_init(&gp03,&sgp03[127],gp03_main,0,0,1);
    proc_init(&gp11,&sgp11[127],gp11_main,1,0,2);
    proc_init(&gp12,&sgp12[127],gp12_main,1,0,2);

    proc_init(&rt01,&srt01[127],rt01_main,0,1,3);
    proc_init(&rt02,&srt02[127],rt02_main,0,1,2);
    proc_init(&rt03,&srt03[127],rt03_main,0,1,1);
    proc_init(&rt11,&srt11[127],rt11_main,1,1,2);
    proc_init(&rt12,&srt12[127],rt12_main,1,1,2);
    proc_init(&rt21,&srt21[127],rt21_main,2,1,1);

    sem_init( &my_sem, 1 );
    sig_init( &my_sig );
    sig_init( &my_sig2 );

    proc_run_no_resched(&gp01);
    proc_run_no_resched(&gp02);
    proc_run_no_resched(&gp03);
    proc_run_no_resched(&gp11);
    proc_run_no_resched(&gp12);

    proc_stop_no_resched(&gp01);
    proc_run_no_resched(&gp01);

    proc_run_no_resched(&rt01);
    proc_run_no_resched(&rt02);
    proc_run_no_resched(&rt03);
    proc_run_no_resched(&rt11);
    proc_run_no_resched(&rt12);
    proc_run_no_resched(&rt21);

    proc_stop_no_resched(&rt01);
    proc_run_no_resched(&rt01);

    start_bugurt();

    timer_t blink;
    update_system_timer();
    CLEAR_TIMER(blink);
    while(1){
        update_system_timer();
        if(TIMER(blink)>500){
            PORTB ^=0x55;
            CLEAR_TIMER(blink);
            sig_signal( &my_sig2 );
            proc_run_no_resched(&rt21);
        }
    }
}
