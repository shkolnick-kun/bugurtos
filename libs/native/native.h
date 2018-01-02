#ifndef _NATIVE_H_
#define _NATIVE_H_

#include <bugurt.h>

/*!
\file
\~russian
\brief Прослойка совместимости с версией 2.0.x.

В этом файле определены имена функций, макросов и типов данных, а так же включены другие заголовки.
\~english
\brief Native lib v2.0.x compatibility layer.

In this file there are definitions of functions, macros and data types. Also this file includes other native lib headers.
*/


//Backward compatibility layer
#define init_bugurt         bgrt_init                    /*!< \~russian \brief Инициация Ядра ОС. \~english \brief An OS kernel initialization. */
#define start_bugurt        bgrt_start                   /*!< \~russian \brief Запуск Ядра ОС. \~english \brief An OS kernel start. */

#define disable_interrupts  BGRT_INT_LOCK      /*!< \~russian \brief Запретить прерывания. \~english \brief Disable interrupts. */
#define enable_interrupts   BGRT_INT_FREE       /*!< \~russian \brief Разрешить прерывания. \~english \brief Enable interrupts. */

#define proc_init_cs        bgrt_priv_proc_init              /*!< \~russian \brief Инициация процесса из обработчика прерывания или критической секции. \~english \brief A process initialization from ISR or critical section. */
#define proc_init           bgrt_proc_init               /*!< \~russian \brief Инициация процесса. \~english \brief A process initialization. */

#define proc_run_cs         bgrt_priv_proc_run               /*!< \~russian \brief Запуск процесса из обработчика прерывания или критической секции. \~english \brief Run a process from ISR or critical section. */
#define proc_run            BGRT_PROC_RUN                /*!< \~russian \brief Запуск процесса. \~english \brief Run a process. */

#define proc_stop_cs        bgrt_priv_proc_stop              /*!< \~russian \brief Останов процесса из обработчика прерывания или критической секции. \~english \brief Stop a process from ISR or critical section. */
#define proc_stop           BGRT_PROC_STOP               /*!< \~russian \brief Останов процесса. \~english \brief Stop a process. */

#define proc_restart_cs     bgrt_priv_proc_restart           /*!< \~russian \brief Перезапустить процесс из обработчика прерывания. \~english \brief Restart a process from ISR. */
#define proc_restart        BGRT_PROC_RESTART            /*!< \~russian \brief Перезапустить процесс. \~english \brief Restart a process. */

#define proc_self_stop      BGRT_PROC_SELF_STOP          /*!< \~russian \brief Останов вызывающего процесса. \~english \brief Stop a caller process. */
#define proc_reset_watchdog BGRT_PROC_RESET_WATCHDOG     /*!< \~russian \brief Сброс вачдог. \~english \brief Reset a process watchdog. */

#define proc_lock           BGRT_PROC_LOCK               /*!< \~russian \brief Запретить останов процесса. \~english \brief Disable a process stop. */
#define proc_free           BGRT_PROC_FREE               /*!< \~russian \brief Разрешить останов процесса. \~english \brief Enable a process stop. */

#define proc_set_prio       BGRT_PROC_SET_PRIO           /*!< \~russian \brief Установить приоритет процесса. \~english \brief Set a process priority. */

static inline bgrt_prio_t proc_get_prio(BGRT_PID_T * pid)/*!< \~russian \brief Прочитать приоритет процесса. \~english \brief Get a process priority. */
{
    bgrt_prio_t ret;
    BGRT_PROC_GET_PRIO(pid, &ret);
    return ret;
}

#define sched_proc_yeld     bgrt_sched_proc_yeld         /*!< \~russian \brief Передать управление следующему процессу. \~english \brief Pass control to next ready process. */

#define TIMER               BGRT_TIMER                   /*!< \~russian \brief Получить значение таймера. \~english \brief Get timer value. */
#define CLEAR_TIMER         BGRT_CLEAR_TIMER             /*!< \~russian \brief Сбросить таймер. \~english \brief Clear a timer. */
#define wait_time           bgrt_wait_time               /*!< \~russian \brief ПРограммная задержка. \~english \brief A software delay. */

#define CRIT_SEC_ENTER      BGRT_CRIT_SEC_ENTER          /*!< \~russian \brief Начало критической секции. \~english \brief A criyical section start. */
#define CRIT_SEC_EXIT       BGRT_CRIT_SEC_EXIT           /*!< \~russian \brief Конец критической секции. \~english \brief A critical section end. */

#define status_t            bgrt_st_t                    /*!< \~russian \brief Тип возвращаемых статусов. \~english \brief An execution status type. */

//Sync primitives
#include "ipc.h"
#include "sem.h"
#include "mutex.h"
#include "cond.h"
#include "sig.h"

#endif // _NATIVE_H_
