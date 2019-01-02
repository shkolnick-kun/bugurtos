# Getting started with BuguRTOS-4.0.x

## Hello, %username%!!!
If you are reading this flow of words, then you may be interested in BuguRTOS.
In this document you will get **basic concepts** and **first step instructions** of writing BuguRTOS apps.

### What is BuguRTOS?
BuguRTOS is an embedded OS kernel, written by
anonymous for [LULZZZZ](https://www.google.com/search?q=LULZ&ie=utf-8&oe=utf-8).

You must bee familiar with an OS on your own computer, and you may think that every OS must have a bunch of software,
[GUI](http://en.wikipedia.org/wiki/Graphical_user_interface) or at least console interface.
If you are, well, I have bad news for you.

People mean different things when they talk about OS:
some people think that OS is some kernel with minimal set of system libs and software,
others think that OS is the wallpaper on their desktop,
and some people think that OS is a software library, that enables execution of "many" processes on "small number" of CPUs.

BuguRTOS now is such a library. In fact BuguRTOS is a set of source and header files, written in C and assembler,
that you can use in your project of
[Giant](http://www.themoscowtimes.com/business/article/russia-wants-in-on-a-killer-robot-future/500203.html) [Anthropomorphic](http://www.youtube.com/watch?v=UPh7uFMLmSw) [Combat](https://www.youtube.com/watch?v=NDsVhpA24n4) [Robot](http://player.vimeo.com/video/75781782?title=0&byline=0&portrait=0&autoplay=1) firmware.

### Why should I need this?
If you like to blink a LED on you Arduino<sup>TM</sup>, then you definitely **DON'T NEED AN OS!**
But if you want to write big and complex firmware which must do many tasks simultaneously,
then you probably need one.

### But why?
Because OS enables you to **control the complexity** of your project and to use **any styles of programming**
and **any suitable software libs**.

### Why BuguRTOS?
You can use any OS you like. [Here](http://en.wikipedia.org/wiki/List_of_real-time_operating_systems)
you can see the list of different RTOS.

### What do I need?
 1. You need to get OS source code, check releases on the project page.
 2. You need a cross toolchain for your processor.
 3. You may need some IDE, I prefer to use Code::Blocks.
 4. You need to configure your build environment:
   * Create a workspace dir.
   * Create a project dir.
   * Copy BuguRTOS to some dir in your workspace.
   * Write config.h file or take one from tests or example config files.
   * Add files to your project and configure it:
     *  add following dirs to compiler search path:
        * [%bugurtos_dir%]/kernel,
        * [%bugurtos_dir%]/kernel/default,
        * [%bugurtos_dir%]/libs/native,
        * [%bugurtos_dir%]/arch/[%processor%]/[%toolchain%].
   * Write your program, in **main.c** you may write something like:
```C
    #include<native.h> //Native API include
    /*Project includes, defines, declarations etc.*/

    /*
    Some other code here.
    */
    int main(void)
    {
    	bgrt_init();
    	/*Initialize everything*/
    	bgrt_start();
    	/*
    	Don't write anything here, as control never reaches this place.
    	*/
    }
```
   * Try to build your project.
   * ??????
   * PROFIT!!!

## Inside BuguRTOS.
First of all, multitasking OS is scheduler and other basic process (task,thread etc.) control services.
All this stuff will be described below.

## Interrupts.
If you want to use BuguRTOS API inside interrupts, then you need to declare your Interrupt Service Routine (ISR) with **BGRT_ISR** macro.
This macro gives a proper wrapper for user ISR. Real ISR should be as small as possible and use as little resources as possible.
If you need to do some complex work, then you should use virtual interrupt or atomic notification for such work.

#### WARNING!!!
Since BuguRTOS-1.0.0 no context switch is done on ISR enter!
This may lead to stack overflow on some architectures!!!

Example:
```C
BGRT_ISR(SOME_INTERRUPT)
{
    /*Do something.*/
}
```
### Virtual interrupts.
The BuguRTOS kernel have an optional interrupt virtualization layer. Virtual interrupts are declared using **bgrt_vint_t** type.
Virtual interrupts have a software priority which is used when they are scheduled for execution.
Also one virtual ISR may be used to process different interrupt sources. In such case one may use an argument pointer to process different data sets with one ISR.

Example:
```C
bgrt_vint_t my_vint;

void do_my_vint(void * arg)
{
    /*Do some complex work.*/
}

int main(void)
{
    /*On init phase do:*/

    /*On interrupt firing do_my_vint(some_arg) will be called.*/
    bgrt_vint_init(&my_vint, MY_VINT_PRIORITY, (bgrt_code_t)do_my_vint, (void *)some_arg);
    /*Some other init code ...*/
}

BGRT_ISR(SOME_INTERRUPT)
{
    /*Do something.*/

    /*
    Now fire a virtual interrupt for some complex work.
    */

    /*
    BGRT_KBLOCK is wrapper macro for kernel block (a control structure
    which is responsible kernel services on certain CPU).

    BGRT_KBLOCK.vic is virtual interrupt controller.
    */
    BGRT_VINT_PUSH_ISR(&my_vint, &BGRT_KBLOCK.vic);
}
```

### Atomic notification
Atomic notifications are done with inline functions bgrt_atm_init, bgrt_atm_bset, bgrt_atm_bget, bgrt_atm_bclr and BGRT_ATM_BSET_ISR macro.
Here is the usage example.
```C
bgrt_map_t var;

/*Some place in the code*/
{
    bgrt_atm_init(&var);
}

BGRT_ISR(SOME_INTERRUPT)
{
    /*Do something.*/

    /*
    Now fire a virtual interrupt for some complex work.
    */

    BGRT_ATM_BSET_ISR(&var, SET_MASK); /*This call will set SET_MASK bits in var*/
}

/*Some other later place in code*/
{
    if (bgrt_atm_bget(&var, GET_MASK)) /*Flags are not affected by this call.*/
    {
        /*Handle GET_MASK flags here*/
    }
}

/*Some other later place in code*/
{
    if (bgrt_atm_bclr(&var, CLR_MASK)) /*This call will clear CLR_MASK bits in var*/
    {
        /*Handle CLR_MASK flags here*/
    }
}

```

### Processes.
In different OSes it may be called process, task, thread etc., but the main pint is
**independent CPU instruction execution flow**.

So, the process is a part of a program that is being executed. It has its own **pmain** function, and that
**pmain** may be written as there are no other processes running!

Each process has its own [stack](http://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29).

Processes in BuguRTOS can be divided in two groups, they are **real time** and **general purpose** processes.
The main difference of these two groups is scheduling policy, see Scheduler.

Processes may have common resources, for example, two processes may have common **pmain** function,
in such case we may talk about two running instances of such **pmain**.

When the scheduler suspends a process execution it calls **sv_hook** function, and when it unsuspends a process
execution, **rs_hook** is called.

Functions **pmain**, **sv_hook** and **rs_hook** take one argument of __void *__ type.
This argument is supposed to be a pointer to some data storage, that may differ from one running instance of
**pmain** to another.

Processes may have **common data**, user is responsible of protecting such **common data** with OS
synchronization primitives. If user **fails** to do that, then
[race condition](http://en.wikipedia.org/wiki/Race_condition) may and will occur.

Processes **must** have **different nonoverlapping stacks**. Actually user may allocate one stack for two or
more processes, but in such case user **must make sure** that only one such process runs at any time.

#### What is needed to create a process?
You need to do the steps below.
 1. Declare a variable of **bgrt_proc_t** type (a process descriptor). It's better to declare it global.
 2. Declare an array of **stack_t**, this is a process stack. It's better to declare it global too.
 3. Write some **pmain**:
```C
    void my_process_main(void * arg)
    {
        /* Do something.*/
    }
```
 4. Call **bgrt_proc_init_cs** or **proc_init**:
```C
    // This function is called before bgrt_start() call in main or in ISR
    bgrt_proc_init_cs(
 		&my_proc,  /*a process descriptor pointer  */
 		my_process_main, /*a process main function pointer */
 		my_sv_hook, /* «sv_hook» function pointer */
 		my_rs_hook, /* «rs_hook» function pointer */
 	 	my_main_arg, /*a process arg pointer */
 		&my_stack[STACK_LENTH — 1],  /* a stack bottom pointer*/
 		MY_PRIORITY, /*a process priority, see Scheduler */
 		MY_TIME_QUANT, /*a process time slice, see Scheduler */
 		IS_RT, /* 1 for **real time**, 0 for **general purpose** processes, see Scheduler */
 		);
    // If you need to initiate process from other process, then you MUST use proc_init instead.
```
 5. Call **bgrt_proc_run_cs** or **bgrt_proc_run**:
```C
    bgrt_proc_run_cs(&my_proc); // Use in ISR or from main before bgrt_start() call.
    // If you need to run a process from an other process, then you MUST use bgrt_proc_run instead.
```
#### What can I do in process main?
You can do everything you do in programs main. Here are some functions, which control a process execution:
```C
bgrt_proc_wd_reset(); /*This resets watchdog of real time process*/
bgrt_proc_self_stop();      /*This stops caller*/
bgrt_proc_lock();           /*This makes caller "unstoppable" by bgrt_proc_stop function.*/
bgrt_proc_free();           /*This makes caller "stoppable" by bgrt_proc_stop function.*/
/*Calls of bgrt_proc_lock and bgrt_proc_free may be nested, in such case caller is "unstoppable"
while nest count is greater than zero.*/
bgrt_sched_proc_yeld();     /*This suspends caller execution and resumes next ready process execution.
If caller is real time, then its watchdog gets reset,
caller is placed to the end of ready process list.
if caller is general purpose, then it is placed to the end of expired process list.
This function returns nonzero, if power can be saved.*/
```
Also, be careful with static variables, as they a common for all running instances.
To deal with common resources, events and time user needs some synchronization primitives.
BuguRTOS-4.0.x kernel provides following primitives:
 1. software timers for time management;
 2. critical sections for fast data access control;
 3. basic synchronization primitive (bgrt_sync_t) which can be used to construct conventional ones such as mutex, semaphore etc.

Software timers and critical sections are supposed to be used directly.

On the other hand, basic synchronization primitive is supposed to be used through libraries which provide some
synchronization primitives to user.
This primitive in fact does jobs which are common for all blocking synchronization primitives (process suspend,
queuing, resume, priority inheritance and priority ceiling), so library coder doesn't need to implement these
things from scratch.

There is only **native** library at the moment, which provides following sync primitives:
 1. mutex;
 2. counting semaphore;
 3. conditional variable;
 4. synchronous nonbuffered IPC.

These primitives will be described in next chapters.

#### What can I do with processes?
There are some functions to control process execution, here they are:
```C
bgrt_proc_stop(&some_proc);     /*This may stop a process*/
bgrt_proc_stop_cs(&some_proc); /*Same function for ISR and critical section calls.*/
bgrt_proc_restart(&some_proc);  /*This may restart a process, if it has returned from pmain.*/
bgrt_proc_restart_cs(&some_proc);/*Same function for ISR and critical section calls.*/
bgrt_proc_set_prio(&some_proc, some_priority); /* This sets basic process priority.*/
```
### Scheduler.
A scheduler is one of the most important OS component. It enables multitasking by switching processes contexts.
In BuguRTOS scheduler works on periodic system timer interrupts or when rescheduling needed.

#### How does it work?
To enable scheduler there must be one hardware timer, which can generate periodic interrupts (for example one
interrupt per millisecond).

System timer interrupt service routine saves a current process context to current process stack; calls
**sched_schedule** function, which selects next process to execute; switches to next process stack; restores
next process context and returns. Next process execution resumes on system timer ISR return.

Rescheduling works simpler: **sched_reschedule** function just selects most prioritized process.

All BuguRTOS system call handlers as well as scheduler routines have O(1) complexity, which means, that
their execution time has **bounded upper limit**. This feature enables BuguRTOS usage in hard real time
applications.

#### How next process is selected?
As described above, there are two kinds of processes in BuguRTOS, they are **general purpose** and
**real time** processes.

**General purpose** processes are supposed to run in a background of **real time** processes.
On the other hand, **real time** processes are supposed to be stopped most of the time and
serve corespondent events.

BuguRTOS has preemptive scheduler, so most prioritized processes are executed first.
If there are two or more processes of the same priority, they are executed in **fifo** manner, so first started process gets executed first.

Every process has its own timer, which counts process execution time. A process may be preempted by a scheduler
on every system timer tick (**round-robin** scheduling policy), or only when its timer expires (clean **fifo**
scheduling policy).

In **real time** processes timer is used as watchdog, so when watchdog expires scheduler stops such process
and gives processor to next ready process. Watchdog expiration is exceptional situation which needs handling,
so a process with expired watchdog can't be run by **bgrt_proc_run** function, typically it must be restarted
(sometimes dependent processes need restart too).

In **general purpose** processes timer is used to count process time slice, so when process time slice expires a
process gets placed to expired process list and its timer gets reset.

#### What is process priority?
A process priority is metric of level of a process importance.
More important processes must get their time earlier than less important.
In BuguRTOS zero is the highest priority and lowest priority is BGRT_PROC_PRIO_LOWEST.

#### What is process time slice?
A process time slice is amount of time when process can run
without being stopped or moved to expired process list.
Time slices are used to share CPU time between processes in needed proportions and to guarantee,
that ready processes of at least highest priority will get their CPU time.

### Process synchronization primitives.
During development process people encounter process synchronization problems.
Processes must be synchronized on time, events or common data access.
BuguRTOS and its **native** lib provide some synchronization primitives.

#### BuguRTOS kernel primitives.
BuguRTOS kernel provides three types of primitives, described below.

##### Software timers.
Software timers are used for time synchronization and time management.
The unit of time measurement in BuguRTOS is system timer tick.
Software timer is a variable of **timer_t** type.
Here are some timer management tools:
```C
timer_t some_timer;           /*A timer_t variable declaration.*/
BGRT_CLEAR_TIMER(some_timer);    /*This macro clears a timer,
                              it also must be used to initiate timers.*/
BGRT_TIMER(some_timer);          /*This macro gives a number of ticks since last timer clear.
                              It may be used to count and compare time intervals.*/
void bgrt_wait_time(some_time);  /*This function spins for a given time, may be used for delays, etc.*/

/*
If you want different processes to have
exact time based synchronization
then you should use these macros:
*/
/*
WARNING!!!
These macros are not thread safe!
You should use one timer per process.
*/
BGRT_SET_TIMER(some_timer, next);    /*This macro does some_timer += next, so when 
                              BGRT_TIMER(0) becomes greater than some_timer we may do some action.*/
BGRT_WAIT_INTERVAL(some_timer, next); /*This macro set some_timer and spins until
                              BGRT_TIMER(0) becomes greater than some_timer.*/
```
##### Critical sections.
A critical section is a part of a program with disabled interrupts.
Critical sections may be nested.
To enter critical section one must call **ENTER_CRIT_SEC** macro.
To exit critical section one must call **EXIT_CRIT_SEC** macro.
In case of nesting critical sections interrupts are disabled on first critical section enter
and enabled on last critical section exit.
A program is supposed to exit critical sections **as fast as possible**.

##### Basic synchronization primitive.
BuguRTOS kernel provides **bgrt_sync_t** primitive for library usage.
It is documented in BuguRTOS API reference manual, check releases on the project page.
Also you can see **native** lib for examples of **bgrt_sync_t** usage.

#### Native lib synchronization primitives.
There are some primitives, implemented in **native** lib.
All these primitives use **bgrt_sync_t** primitive, provided by BuguRTOS kernel.

##### Mutexes.
Mutex is mutual exclusion primitive.
It ensures that only one process can access to common data at any time.
Mutex must be declared as **bgrt_mtx_t** variable.
Here are mutex handling tools:
```C
#include <native.h>

bgrt_mtx_t some_mutex;                    /*This is mutex declaration*/
bgrt_st_t status;

bgrt_mtx_init(&some_mutex, MUTEX_PRIO); /*This initiates mutex, for usage in processes main,
                                       one must use bgrt_mtx_init_cs in critical sections etc.*/
status = bgrt_mtx_try_lock(&some_mutex);/*This function tries to lock mutex, caller is not blocked.*/
status = bgrt_mtx_lock(&some_mutex);    /*This function locks mutex, caller is blocked
                                       until mutex is free.*/
status = bgrt_mtx_free(&some_mutex);    /*This function frees mutex, if there are blocked processes,
                                       then mutex is passed to most prioritized of them.*/
```
Mutex in **native** lib combines priority inheritance and immediate priority ceiling protocols,
so one must pass a mutex priority on mutex initialization.
Immediate priority ceiling is supposed to be main protocol, and priority inheritance is
considered to be fallback protocol, if user fails to assign correct priority to a mutex.

Mutex must be freed by its owner process, as other processes can't free it.

##### Counting semaphores.
Counting semaphore should be used in client-server communications, see
[producer-consumer problem](http://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem) for background.
Semaphore must be declared as **bgrt_sem_t** variable.
Here are semaphore tools, provided by **native** lib:
```C
#include <native.h>

bgrt_sem_t some_sem;                    /*This is semaphore declaration*/
bgrt_st_t status;

bgrt_sem_init(&some_sem, COUNT_INIT); /*This initiates semaphore, for usage in processes main,
                                   one must use bgrt_sem_init_cs in critical sections etc.*/
status = bgrt_sem_try_lock(&some_sem);/*This function tries to lock semaphore, caller is not blocked.*/
status = bgrt_sem_lock(&some_sem);    /*This function locks semaphore, caller is blocked
                                   until semaphore is free.*/
status = bgrt_sem_free(&some_sem);    /*This function frees semaphore, if there are blocked processes,
                                   then most prioritized of them gets resumed.*/

/*Semaphore in BuguRTOS may have an owner process, as bgrt_sync_t is used as bgrt_sem_t parent type.*/
BGRT_SYNC_SET_OWNER(&some_sem, &some_proc); /*This macro assigns an owner*/
BGRT_SYNC_SET_OWNER(&some_sem, 0);           /*This macro clears an owner*/
```
Counting semaphore may be locked by one process and freed by another.
Counting semaphore may have an owner process, in such case every process can lock this semaphore,
but only owner can free it.

##### Conditional variables.
Conditional variables are used in client-server communications just like semaphores,
they can be used for data or event synchronization.
Conditionals are used with mutexes. Here are tools for conditional variable handling:
```C
#include <native.h>

bgrt_mtx_t some_mutex;
bgrt_cond_t some_cond;
bgrt_st_t status;

bgrt_mtx_init(&some_mutex, MUTEX_PRIO);
bgrt_cond_init(&some_cond );                       /*There is also *_cs version of this.*/

// Conditional wait
status = bgrt_mtx_lock(&some_mutex);            /*The mutex must be locked.*/
/*Do something.*/
status = bgrt_cond_wait(&some_cond, &some_mutex); /*Wait for conditional (caller will block).*/
/*Do something.*/
status = bgrt_mtx_free(&some_mutex);            /*Must free the mutex*/

// Conditional signal
status = bgrt_mtx_lock(&some_mutex);            /*Mutex must be locked.*/
/*Do something.*/
status = bgrt_cond_signal(&some_cond);             /*Wake up most prioritized waiting process.*/
status = bgrt_mtx_free(&some_mutex);            /*Must free the mutex*/

// Conditional broadcast
status = bgrt_mtx_lock(&some_mutex);            /*Mutex must be locked.*/
/*Do something.*/
status = bgrt_cond_broadcast(&some_cond);         /*Wake up all waiting processes.*/
status = bgrt_mtx_free(&some_mutex);            /*Must free the mutex*/

/*Conditional in BuguRTOS may have an owner process, as bgrt_sync_t is used as bgrt_cond_t parent type.*/
BGRT_SYNC_SET_OWNER(&some_cond, &some_proc); /*This macro assigns an owner*/
BGRT_SYNC_SET_OWNER(&some_cond, 0);           /*This macro clears an owner*/
```
Conditionals may have an owner process, in such case only an owner can broadcast and signal conditionals.

##### IPC.
BuguRTOS **native** lib provides unbuffered blocking IPC.
This IPC implementation uses rendezvous method to pass messages between processes.
Messages are passed by reference through endpoints.
Every endpoint has its owner process, which receives messages.
Priority inheritance/ceiling protocol is used in IPC.
An IPC endpoint is a variable of bgrt_ipc_t type.
Here are IPC tools:
```C
#include <native.h>

bgrt_ipc_t some_ep;
bgrt_st_t status;
bgrt_proc_t * wait_for = 0;

bgrt_ipc_init(&some_ep);                       /*This function has *_cs variant.*/
BGRT_SYNC_SET_OWNER(&some_ep, &some_proccess); /*Set an owner after init. This macro must be called
                                            from a process main with interrupts enabled.*/
/*
Wait for a message.
This function may be closed (wait for specific sender) or open (wait for any sender).
This function may block caller process (BLOCKC_CALLER != 0) or not (BLOCKC_CALLER == 0).

This call is open, as (wait_for == 0).
After this call wait_for will point to a sender process.
*/
status = bgrt_ipc_wait(&some_ep, &wait_for, BLOCK_CALLER);

/*
Send a message.
A sender will be blocked until reply.
*/
status = bgrt_ipc_send(&some_ep, &some_msg);

/*
Reply to the sender.

Second arg is sender process id.
*/
status = bgrt_ipc_reply(&some_ep, wait_for);
```
## Good luck!
Good luck %username%, write elegant, robust and maintainable code!

I hope you'll use BuguRTOS in your projects.

