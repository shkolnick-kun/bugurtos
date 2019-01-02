#ifndef NATIVE_H
#define NATIVE_H

#include <bugurt.h>
BGRT_CDECL_BEGIN
/*!
\file
\~russian
\brief Нативный API.

В этом файле определены имена функций, макросов и типов данных, а так же включены другие заголовки.
\~english
\brief Native API.

In this file there are definitions of functions, macros and data types. Also this file includes other native lib headers.
*/
#define bgrt_proc_init_cs    bgrt_priv_proc_init          /*!< \~russian \brief Инициация процесса из обработчика прерывания или критической секции. \~english \brief A process initialization from ISR or critical section. */

#define bgrt_proc_run_cs     bgrt_priv_proc_run           /*!< \~russian \brief Запуск процесса из обработчика прерывания или критической секции. \~english \brief Run a process from ISR or critical section. */
#define bgrt_proc_run        BGRT_PROC_RUN                /*!< \~russian \brief Запуск процесса. \~english \brief Run a process. */

#define bgrt_proc_stop_cs    bgrt_priv_proc_stop          /*!< \~russian \brief Останов процесса из обработчика прерывания или критической секции. \~english \brief Stop a process from ISR or critical section. */
#define bgrt_proc_stop       BGRT_PROC_STOP               /*!< \~russian \brief Останов процесса. \~english \brief Stop a process. */

#define bgrt_proc_restart_cs bgrt_priv_proc_restart       /*!< \~russian \brief Перезапустить процесс из обработчика прерывания. \~english \brief Restart a process from ISR. */
#define bgrt_proc_restart    BGRT_PROC_RESTART            /*!< \~russian \brief Перезапустить процесс. \~english \brief Restart a process. */

#define bgrt_proc_self_stop  BGRT_PROC_SELF_STOP          /*!< \~russian \brief Останов вызывающего процесса. \~english \brief Stop a caller process. */
#define bgrt_proc_wd_reset   BGRT_PROC_RESET_WATCHDOG     /*!< \~russian \brief Сброс вачдог. \~english \brief Reset a process watchdog. */

#define bgrt_proc_lock       BGRT_PROC_LOCK               /*!< \~russian \brief Запретить останов процесса. \~english \brief Disable a process stop. */
#define bgrt_proc_free       BGRT_PROC_FREE               /*!< \~russian \brief Разрешить останов процесса. \~english \brief Enable a process stop. */

#define bgrt_proc_set_prio   BGRT_PROC_SET_PRIO           /*!< \~russian \brief Установить приоритет процесса. \~english \brief Set a process priority. */

static inline bgrt_prio_t bgrt_proc_get_prio(BGRT_PID_T pid)/*!< \~russian Прочитать приоритет процесса. \~english Get a process priority. */
{
    bgrt_prio_t ret;
    BGRT_PROC_GET_PRIO(pid, &ret);
    return ret;
}

/*Sync primitives*/
#include "ipc.h"
#include "sem.h"
#include "mutex.h"
#include "cond.h"

BGRT_CDECL_END
#endif /*NATIVE_H*/
