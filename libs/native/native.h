#ifndef _NATIVE_H_
#define _NATIVE_H_

#include <bugurt.h>

//Backward compatibility layer
#define init_bugurt         bgrt_init
#define start_bugurt        bgrt_start

#define disable_interrupts  bgrt_disable_interrupts
#define enable_interrupts   bgrt_enable_interrupts

#define proc_init_isr       _bgrt_proc_init
#define proc_init           bgrt_proc_init

#define proc_run_isr        _bgrt_proc_run
#define proc_run            bgrt_proc_run

#define proc_stop_isr       _bgrt_proc_stop
#define proc_stop           bgrt_proc_stop

#define proc_self_stop      bgrt_proc_self_stop
#define proc_reset_watchdog bgrt_proc_reset_watchdog

#define proc_lock           bgrt_proc_lock
#define proc_free           bgrt_proc_free

#define proc_set_prio       bgrt_proc_set_prio
#define proc_get_prio       bgrt_proc_get_prio

#define sched_proc_yeld     bgrt_sched_proc_yeld

#define TIMER               BGRT_TIMER
#define CLEAR_TIMER         BGRT_CLEAR_TIMER
#define wait_time           bgrt_wait_time

#define CRIT_SEC_ENTER      BGRT_CRIT_SEC_ENTER
#define CRIT_SEC_EXIT       BGRT_CRIT_SEC_ENXIT

#define status_t            bgrt_st_t

//Sync primitives
#include "ipc.h"
#include "sem.h"
#include "mutex.h"
#include "cond.h"
#include "sig.h"

#endif // _NATIVE_H_
