#ifndef _BUGURT_SYSCALL_H_
#define _BUGURT_SYSCALL_H_

#include"../../include/bugurt.h"

extern unsigned char syscall_num;
extern void * syscall_arg;
extern const code_t syscall_routine[];

void do_syscall(void);

extern void syscall( unsigned char num, void * arg );

///=================================================================
///                 ОБРАБОТЧИКИ СИСТЕМНЫХ ВЫЗОВОВ
///=================================================================
///                   Управление процессами
typedef struct {
    proc_t * proc;
    code_t pmain;
    code_t sv_hook;
    code_t rs_hook;
    void * arg;
    stack_t *sstart;
    prio_t prio;
    timer_t time_quant;
    bool_t is_rt;
} proc_init_arg_t;

void scall_proc_init( void * arg );
//----------------------------------------------------------------------
typedef struct{
    proc_t * proc;
    bool_t scall_ret;
}proc_runtime_arg_t;

void scall_proc_run( void * arg );
void scall_proc_restart( void * arg );
void scall_proc_stop( void * arg );
//----------------------------------------------------------------------
void scall_proc_self_stop( void * arg );
//----------------------------------------------------------------------
void scall_proc_terminate( void * arg );
//----------------------------------------------------------------------
void scall_proc_flag_stop( void * arg );
///=================================================================
///                         Сигналы
void scall_sig_init( void * arg );
void scall_sig_wait( void * arg );
void scall_sig_signal( void * arg );
void scall_sig_broadcast( void * arg );
///=================================================================
///                         Семафоры
typedef struct {
    sem_t * sem;
    count_t count;
}sem_init_arg_t;
void scall_sem_init( void * arg );
//----------------------------------------------------------------------
typedef struct {
    sem_t * sem;
    bool_t scall_ret;
}sem_lock_arg_t;
void scall_sem_lock( void * arg );
//----------------------------------------------------------------------
void scall_sem_unlock( void * arg );
///=================================================================
///                         Мьютексы
typedef struct {
    mutex_t * mutex;
#ifdef CONFIG_USE_HIGHEST_LOCKER
    prio_t prio;
#endif // CONFIG_USE_HIGHEST_LOCKER
}mutex_init_arg_t;
void scall_mutex_init(void * arg);
//----------------------------------------------------------------------
typedef struct {
    mutex_t * mutex;
    bool_t scall_ret;
} mutex_lock_arg_t;
void scall_mutex_lock(void * arg);
void scall_mutex_try_lock(void * arg);
void scall_mutex_unlock(void * arg);

#endif // _BUGURT_SYSCALL_H_
