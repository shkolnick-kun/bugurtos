# Changelog #
  * 0.8.1
    * Fixed [old scheduler code](https://code.google.com/p/bugurtos/issues/detail?id=1&can=1).
    * Fixed [missed wakeup](https://code.google.com/p/bugurtos/issues/detail?id=2&can=1) in sync\_wait call.
    * Added memory barriers in Cortex<sup>TM</sup>-M ports.
    * Deleted proc\_flag\_stop system call.
    * Added proc\_lock and proc\_free system calls.
    * Changed sync\_set\_owner system call behavior. Now sync\_clear\_owner call needed to change owner.
    * Added support of Immediate Ceiling Priority Protocol, now priority control protocol combines both [ICPP](http://en.wikipedia.org/wiki/Priority_ceiling_protocol) and [BPI](http://en.wikipedia.org/wiki/Priority_inheritance).
    * Added generic lib, which supports some traditional sync primitives:
      * mutex;
      * conditional variable;
      * signal (like in 0.6.x and 0.7.x branches);
      * counting semaphore;
      * microkernel style IPC.
  * 0.7.2
    * Fixed wrong [proc\_flag\_stop](https://code.google.com/p/bugurtos/issues/detail?id=3&can=1) behavior.
  * 0.6.5
    * Fixed wrong [proc\_flag\_stop](https://code.google.com/p/bugurtos/issues/detail?id=3&can=1) behavior.
  * 0.8.0
    * New branch added, see [differences](https://code.google.com/p/bugurtos/wiki/NewBranchDifferences) with 0.6.x and 0.7.x branches.
  * 0.7.1
    * Several priority inheritance protocol bugs fixed.
  * 0.7.0
    * Priority inheritance protocol implemented, no more ICPP in 0.7.x branch.
    * Mutex test updated.
  * 0.6.4
    * Cortex<sup>TM</sup>-M4F support added.
    * Tests moved from lpc1xxx to stm32xxxx.
  * 0.6.3
    * Cortex<sup>TM</sup>-M0 support added.
  * 0.6.2
    * Cortex<sup>TM</sup>-M3 support added.
  * 0.6.1
    * Fixed proc\_restart/proc\_restart\_isr bug, no more restart with locked mutexes or semaphores
    * Added scheduler dead spinlock if process lists are empty.
  * 0.6.0
    * pmain return sequence has been revised:
      * no more proc\_wrapper function,
      * proc\_terminate funcion has been added,
      * proc terminate system call has been changed,
      * proc\_stack\_init function has been changed in order to add return adress (a pointer to proc\_terminate function actualy) to initial process context.
  * 0.5.2
    * Low level race condition fixed.
    * Stm8/raisonance tests improved (all paths a relative now).
    * Interrupt driven syscalls on AVR have been removed.
  * 0.5.1
    * Serious signal wait prologue bug fixed!
    * Stm8/raisonance port added.
  * 0.5.0
    * Kernel is now preemptive!
    * Kernel API is frozen.
    * Cross-platform test suite has been added.
    * Some bugs fixed.
    * Documentation has been updated.
  * 0.4.0
    * Simple IPC added.
    * Spinlock wrapper macros added to simplify the source code.
    * Some bugs fixed.
    * Code::Blocks BuguRTOS wizard for AVR updated.
  * 0.3.7
    * sem\_try\_lock added.
    * More code cleanup is done.