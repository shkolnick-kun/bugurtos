# THIS FILE IS WORK IN PROGRESS, IT IS NOT FINISHED YET!!!
# Getting startted with BuguRTOS-0.8.x

##Hello, %username%!!!
If you are reading this flow of words, then you may be interested in BuguRTOS.
In this document you will get **basic concepts** and **first step instructions** of writing BuguRTOS apps.

###What is BuguRTOS?
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
[Giant](http://www.themoscowtimes.com/business/article/russia-wants-in-on-a-killer-robot-future/500203.html) [Anthropomorphic](http://www.youtube.com/watch?v=UPh7uFMLmSw) [Robot](http://player.vimeo.com/video/75781782?title=0&byline=0&portrait=0&autoplay=1) firmware.

###Why should I need this?
If you like to blink a LED on you Arduino<sup>TM</sup>, then you definitely **DON'T NEED AN OS!**
But if you want to write big and complex firmware which must do many tasks simultaneously, 
then you probably need one.

###But why?
Because OS enables you to **control the complexity** of your project and to use **any styles of programming**
and **any suitable software libs**.

###Why BuguRTOS?
You can use any OS you like. [Here](http://en.wikipedia.org/wiki/List_of_real-time_operating_systems) 
you can see the list of different RTOS.

###What do I need?
 1. You need to get OS source code, check releases on the project page.
 2. You need a cross toolchain for your processor.
 3. You may need som IDE, I prefer to use Code::Blocks.
 4. You need to configure your buid environment:
   * Create a workspace dir.
   * Create a project dir.
   * Copy BuguRTOS to some dir in your workspace.
   * Write config.h file or take one from tests or example config files.
   * Add files to your project and configure it:
     *  preinclude config.h;
     *  add following dirs to compiler search path:
        * [%bugurtos_dir%]/kernel, 
        * [%bugurtos_dir%]/libs/generic, 
        * [%bugurtos_dir%]/arch/[%processor%]/[%toolchain%].
   * Write your program, in **main.c** you may write something like:
```C
    // #include<bugurt.h> // For Cortex-M
    #include<bugurt_kernel.h> // For AVR, STM8
    /*Project includes, defines, declarations etc.*/

    void idle_main(void * arg )
    {
    	/*You may write your idle_main or use bultin.*/
    	while(1);
    }
    int main(void)
    {
    	init_bugurt();
    	/*Initialize everything*/
    	start_bugurt();
    	/*
    	Don't write anything here, as control never reaches this place.
    	*/
    }
```
   * Try to build your project.
   * ??????
   * PROFIT!!!

##Inside BuguRTOS.
First of all, multitasking OS is sheduler and other basic process (task,thread etc.) control services.
All this stuff will be described below.

###Process
In different OSes it may be called process, task, thread etc., but the main pint is 
**independent CPU instruction execution flow**.

So, the process is a part of a program that is being executed. It has its own **pmain** function, and that 
**pmain** may be written as there are no other processes running!

Each process has its own [stack](http://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29). 

Processes in BuguRTOS can be devided in two groups, they are **real time** and **general purpose** processes.
The main difference of these two groups is sheduling policy, see Scheduler.

Processes may have common resources, for example, two processes may have common **pmain** function, 
in such case we may talk about two running instances of such **pmain**.

When the scheduler suspends a process execution it calls **sv_hook** function, and when it unsuspends a process 
execution, **rs_hook** is called.

Functions **pmain**, **sv_hook** and **rs_hook** take one argument of __void *__ type. 
This argument is supposed to be a pointer to some data storage, that may differ from one running instanse of 
**pmain** to another.

Processes may have **common data**, user is responsible of pprotecting such **common data** with OS 
synchronization primitives. If user **fails** to do that, then 
[race condition](http://en.wikipedia.org/wiki/Race_condition) may and will occur.

Processes **must** have **different nonoverlapping stacks**. Actually user may allocate one stack for two or 
more processes, but in such case user **must make sure** that only one such process runs at any time.

####What is needed to create a process?
You need to do the steps below.
 1. Declare a variable of **proc_t** type (a process descriptor). It's better to declare it global.
 2. Declare an array of **stack_t**, this is a process stack. It's better to declare it global too.
 3. Write some **pmain**:
```C
    void my_process_main(void * arg)
    {
        /* Do something.*/
    }
```
 4. Call **proc_init_isr** or **proc_init**:
```C
    // This function is called before start_bugurt() call in main or in ISR
    proc_init_isr( 
 		&my_proc,  /*a process decriptor pointer  */
 		my_process_main, /*a process main function pointer */
 		my_sv_hook, /* «sv_hook» function pointer */
 		my_rs_hook, /* «rs_hook» function pointer */
 	 	my_main_arg, /*a process arg pointer */
 		&my_stack[STACK_LENTH — 1],  /* a stack pottom pointer*/
 		MY_PRIORITY, /*a process priority, see Scheduler */
 		MY_TIME_QUANT, /*a process time slice, see Scheduler */
 		IS_RT, /* 1 for **real time**, 0 for **general purpose** processes, see Scheduler */
 		);
    // If you need to initiate process from other process, then you MUST use proc_init instead.
```
 5. Call **proc_run_isr** or **proc_run**:
```C
    proc_run_isr(&my_proc); // Use in ISR or from main before start_bugurt() call.
    // If you need to run a process from an other process, then you MUST use proc_run instead.
```
####What can I do in process main?
You can do everything you do in programs main. Here are some functions, which control a process execution:
```C
proc_reset_watchdog(); /*This resets watchdog of real time process*/
proc_self_stop();      /*This stops caller*/
sched_proc_yeld();     /*This suspends caller execution and resumes next ready process execution. 
If caller is real time, then its wachdog gets reset, 
caller is placed to the end of ready process list. 
if caller is general purpose, then it is placed to the end of expired process list. 
This funtion returns nonzero, if power can be saved.*/
```
Also, be carefull with static variables, as they a common for all running instances.
To deal with common resources, events and time user needs some synchronuzation primitives.
BuguRTOS-0.8.x kernel provides following primitives:
 1. software timers for time management;
 2. critical sections for fast data access control;
 3. basic synchronization primitive (sync_t) which can be used to contruct conventional ones such as mutex, semaphore etc.

Software timers and critical sections are supposed to be used directly. 

On the other hand, basic synchronization primitive is supposed to be used through libraries which provide some
synchronization primitives to user. 
This primitive in fact does jobs which are common for all blocking synchonization primitives (process suspend, 
queueing, resume, priority inheritance and priority ceiling), so library coder doesn't need to implement these 
things from scratch.

There is only **generic** library at the moment, which provides following sync primitives:
 1. mutex;
 2. counting semaphore;
 3. conditional variable;
 4. signal (a kind of event);
 5. synchronous nonbuffered IPC.
These primitives will be descibed in next chapters.

####What can I do with processes?
There are some functions to control process execution, here they are:
```C
proc_stop(&some_proc);     /*This may stop a process*/
proc_stop_isr(&some_proc); /*Same function for ISR and critical section calls.*/
proc_restart(&some_proc);  /*This may restart a process, if it has returned from pmain.*/
proc_restart_isr(&some_proc);/*Same function for ISR and critical section calls.*/
proc_set_prio(&some_proc, some_priority); /* This sets basic process priority.*/
```
###Scheduler
A scheduler is one of the most important OS component. It enables multitasking by switching processes contexts.
In BuguRTOS scheduler works on periodic system timer interrupts or when rescheduling needed.

####How does it work?
To enable scheduler there must be one hardware timer, which can generete periodic interrupts (for example one 
interrupt per millisecond).

System timer interrupt servise routine saves a current process context to current process stack; calls  
**sched_schedule** function, which selsects next process to execute; switches to next process stack; restores 
next process context and returns. Next process execution resumes on system timer ISR return.

Recheduling works simpler: **sched_reschedule** function juct selects most prioritized process.

All BuguRTOS system call handlers as well as scheduler routines have O(1) complexity, which means, that
their execution time has **bounded upper limit**. This feachure enables BuguRTOS usage in hard real time 
applications.

####How next process is selected?
As decribed above, there are two kinds of processes in BuguRTOS, they are **general purpose** and 
**real time** processes.

**General purpose** processes are supposed to run in a background of **real time** processes. 
On the other hand, **real time** processes are supposed to be stoped most of the time and 
serve corespondent events.

BuguRTOS has preemptive scheduler, so most prioritized processes are executed first.
If there are two or more processes of the same priority, they are executed in **fifo** manner, so first started process gets executed first.

Every process has its own timer, which counts process execution time. A process may be preempted by a scheduler 
on every system timer tick (**round robbin** scheduling policy), or only when its timer expires (clean **fifo** 
scheduling policy).

In **real time** processes timer is used as watchdog, so when watchdog expires sheduler stops such process
and gives processor to next ready process. Watchdog expiration is exceptional situation which needs handling,
so a process with expired watchdog can't be run by **proc_run** function, typicaly it must be restarted 
(sometimes dependent processes need restart too).

In **general purpose** processes timer is used to count process time slice, so when process time slice expires a
process gets placed to expired process list and its timer gets reset.

####What is process priority?
A process priority is metric of level of a process importance. 
More ipmortant processes must get their time earlier than less important.
In BuguRTOS zero is the highest priority and lowest priority is PROC_PRIO_LOWEST.

####What is process time slice?
A process time slice is amount of time when process can run 
without being stoped or moved to expired process list.
Time slices are used to share CPU time between processes in needed proportions and to guarantee, 
that ready processes of at least highest priority will get their CPU time.

###Process synchronization primitives.
