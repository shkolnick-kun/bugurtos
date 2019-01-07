# Changelog #
  * 4.0.0
    * Added CoC, now new develpers to our welcoming community.
    * Added deterministic API to software timers.
    * Added NULL pointer checks to native lib functions.
    * Added extern "C" linkage for C++ projects.
    * Added ASSERT for future test reworks.
    * Added Cortex<sup>TM</sup>-M7 port.
    * Reworked kernel and native lib namespaces.
    * Reworked comment style.
    * Decoupled scheduler from interrupt virtualization layer.
    * Reworked scheduler code.
    * Reworked power saving. Now it's done in kernel mode only
    * Fixed API for BGRT_KBLOCK_HPFIC_HOOK macro.
    * Fixed #37 (kernel timer rollover problem).
    * Ported tests to newer libopencm3 version.
    * Deleted signals from native lib.
    * Deleted unneeded files.
    * Updated documentation.
  * 3.0.0
    * API renamed to clarify its usage.
    * Optimized performance(see #32.#33,#34).
      * Added atomic notifications mechanism.
      * Added bgrt_map_search using CLZ on Cortex<sup>TM</sup>-M3,4F.
      * Reworked sem_free, now it is done in FSM in kernel thread.
      * Made BGRT_ISR preemptive on on Cortex<sup>TM</sup>-M3,4F.
    * Added owner feature to native lib semaphores.
    * Fixed #30, now the kernel is more robust to user lib errors.
    * Fixed #31 (logical mistake in native lib semaphore implementation).
    * Reworked virtual interrupt controller, fixed #34 (virtual interrupt leak).
    * Added common files to arch dir.
  * 2.0.0
    * Reworked system call dispatcher.
      [X_MACRO](https://en.wikipedia.org/wiki/X_Macro) is used to generate boilerplate code thus enabling kernel extensions and size optimizations.
    * Reworked kernel API.
    * Updated native lib and getting started guide.
    * The project code has been checked with [Adlint](http://adlint.sourceforge.net/) and annotated.
    * Added STM8/SDCC port.
    * Fixed #20.
    * Fixed #26.
  * 1.0.0
    * Deleted IDLE process and user code execution after start (Oh boy! How do I add CMSIS-RTOS API after this???).
    * Added interrupt virtualization layer.
    * Added kernel thread for system calls and virtual interrupts processing.
    * Added userspace process data for future use in b4-microkernel.
    * Reworked scheduler code to simplify it and to use it in virtual interrupts.
    * Reworked system call dispatcher code.
    * Reworked cyclic system calls to use kernel thread virtual interrupt processing loop instead of user space loops.
    * Modified low level arch-dependent code for new kernel.
  * 0.9.9
    * Tests and arch filesystem structure made standardized;
    * Added BUGURT_INTERRUPT macros to Cortex<sup>TM</sup>-Mx ports;
    * Added docs to main tree;
    * Name space changes:
      * Added BGRT_ and bgrt_ prefixes to avoid naming conflicts in future;
      * Deleted _isr/_ISR postfixes;
      * Cleaned up namespace;
    * Enabled user code execution after bgrt_start (by not calling of bgrt_idle_main in bgrt_start) as config option;
    * System call dispatcher changes:
      * Made system call dispatcher replaceable;
      * Made system call handlers typed;
      * Fixed user system call arg type (union instead of struct);
    * Process control changes:
      * Added BGRT_PID_T for process identification in process context, bgrt_proc_t pointers are used in kernel context;
      * Added BGRT_PID_TO_PROC, BGRT_PROC_TO_PID, BGRT_PID_NOTHING macros;
      * Added BGRT_SYSCALL_PROC_GET_PRIO, BGRT_SYSCALL_PROC_GET_ID syscalls and correspondent caller functions;
      * Removed dead some code;
    * Synchronization control changes:
      * Deleted SYSCALL_WAKE_AND_SLEEP SYSCALL_WAKE_AND_WAIT syscalls;
      * Added BGRT_SYSCALL_SYNC_GET_OWNER syscall;
      * Added snum (number of sleeping processes) field to bgrt_sync_t;
      * Revised asynchronous wakeup protocol (various changes and fixes);
      * Revised synchronization API due to previous changes;
      * Fixed priority inversion (#14);
      * Upgraded tests.
    * Native lib changes:
      * Added native.h to native lib;
      * Upgraded native lib.
  * 0.6.6, 0.7.3
    * Ported Cortex<sup>TM</sup>-Mx tests to [libopencm3](https://github.com/libopencm3/libopencm3).
    * Backported vsmp from 0.8.4
  * 0.8.4
    * Fixed design issues in basic synchronization primitive:
      * added asynchronous wakes;
      * deleted sync_clear_owner function;
      * added sync_own and sync_touch functions;
      * changed sync_set_owner behavior.
      * reworked sync tests.
    * Fixed race condition in vsmp (see  #12).
    * Reworked generic lib:
      * updated generic lib code to use new kernel version;
      * added sem_free_isr function.
  * 0.8.3
    * Merged [spelling correction](https://github.com/shkolnick-kun/bugurtos/commit/c4ae75fca01df5f874169c9a348387baf187c9f7) from [dartraiden](https://github.com/dartraiden).
    * Added argument checks to proc.c.
    * Added status_t, statuses are global now.
    * Ported Cortex<sup>TM</sup>-Mx tests to [libopencm3](https://github.com/libopencm3/libopencm3).
    * Fixed [several bugs](https://github.com/shkolnick-kun/bugurtos/issues/8) in VSMP port.
    * Revised tests.
    * Fixed [stupid mistakes](https://github.com/shkolnick-kun/bugurtos/issues/9) in sync test.
    * Kernel is supposed to stabilize now. Development will be focused on libs, ports and bug fixes since this release.
  * 0.8.2
    * Added cnt_lock to proc_t, renamed PROC_FLG_BLOCK to PROC_FLG_LOCK, PROC_FLG_LOCK behavior is now independent from proc->lres.
    * Added FIFO scheduler policy and PROC_FLG_RR to switch to Round Robin sched policy (default).
    * Removed unused functions.
    * Removed PROC_PRE_STOP flag processing in sync.c.
    * Added timeout support to kernel.
    * Fixed [PROC_SET_STATE](https://github.com/shkolnick-kun/bugurtos/issues/5) macro.
    * Fixed [wrong sync owner handling order](https://github.com/shkolnick-kun/bugurtos/issues/4).
    * Added -Os flag to CM0, CM3, CM4F, AVR test projects.
    * Fixed [obsolete scheduler code](https://github.com/shkolnick-kun/bugurtos/issues/6).
  * 0.8.1
    * Fixed [old scheduler code](https://github.com/shkolnick-kun/bugurtos/issues/1).
    * Fixed [missed wakeup](https://github.com/shkolnick-kun/bugurtos/issues/2) in sync\_wait call.
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
    * Fixed wrong [proc\_flag\_stop](https://github.com/shkolnick-kun/bugurtos/issues/3) behavior.
  * 0.6.5
    * Fixed wrong [proc\_flag\_stop](https://github.com/shkolnick-kun/bugurtos/issues/3) behavior.
  * 0.8.0
    * New branch added, see [differences](./NewBranchDifferences.md) with 0.6.x and 0.7.x branches.
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
      * proc\_terminate function has been added,
      * proc terminate system call has been changed,
      * proc\_stack\_init function has been changed in order to add return address (a pointer to proc\_terminate function actually) to initial process context.
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
