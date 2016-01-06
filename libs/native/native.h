#ifndef _NATIVE_H_
#define _NATIVE_H_

#include <bugurt.h>

/*!
\file
\~russian
\brief Прослойка совместимости с версией 0.8.4.

В этом файле определены имена функций, макросов и типов данных, а так же включены другие заголовки.
\~english
\brief Native lib v0.8.4 compatibility layer.

In this file there are definitions of functions, macros and data types. Also this file includes other native lib headers.
*/


//Backward compatibility layer
#define init_bugurt         bgrt_init                    /*!< \~russian \brief Инициация Ядра ОС. \~english \brief An OS kernel initialization. */
#define start_bugurt        bgrt_start                   /*!< \~russian \brief Запуск Ядра ОС. \~english \brief An OS kernel start. */

#define disable_interrupts  bgrt_disable_interrupts      /*!< \~russian \brief Запретить прерывания. \~english \brief Disable interrupts. */
#define enable_interrupts   bgrt_enable_interrupts       /*!< \~russian \brief Разрешить прерывания. \~english \brief Enable interrupts. */

#define proc_init_isr       _bgrt_proc_init              /*!< \~russian \brief Инициация процесса из обработчика прерывания или критической секции. \~english \brief A process initialization from ISR or critical section. */
#define proc_init           bgrt_proc_init               /*!< \~russian \brief Инициация процесса. \~english \brief A process initialization. */

#define proc_run_isr        _bgrt_proc_run               /*!< \~russian \brief Запуск процесса из обработчика прерывания или критической секции. \~english \brief Run a process from ISR or critical section. */
#define proc_run            bgrt_proc_run                /*!< \~russian \brief Запуск процесса. \~english \brief Run a process. */

#define proc_stop_isr       _bgrt_proc_stop              /*!< \~russian \brief Останов процесса из обработчика прерывания или критической секции. \~english \brief Stop a process from ISR or critical section. */
#define proc_stop           bgrt_proc_stop               /*!< \~russian \brief Останов процесса. \~english \brief Stop a process. */

#define proc_self_stop      bgrt_proc_self_stop          /*!< \~russian \brief Останов вызывающего процесса. \~english \brief Stop a caller process. */
#define proc_reset_watchdog bgrt_proc_reset_watchdog     /*!< \~russian \brief Сброс вачдог. \~english \brief Reset a process watchdog. */

#define proc_lock           bgrt_proc_lock               /*!< \~russian \brief Запретить останов процесса. \~english \brief Disable a process stop. */
#define proc_free           bgrt_proc_free               /*!< \~russian \brief Разрешить останов процесса. \~english \brief Enable a process stop. */

#define proc_set_prio       bgrt_proc_set_prio           /*!< \~russian \brief Установить приоритет процесса. \~english \brief Set a process priority. */
#define proc_get_prio       bgrt_proc_get_prio           /*!< \~russian \brief Прочитать приоритет процесса. \~english \brief Get a process priority. */

#define sched_proc_yeld     bgrt_sched_proc_yeld         /*!< \~russian \brief Передать управление следующему процессу. \~english \brief Pass control to next ready process. */

#define TIMER               BGRT_TIMER                   /*!< \~russian \brief Получить значение таймера. \~english \brief Get timer value. */
#define CLEAR_TIMER         BGRT_CLEAR_TIMER             /*!< \~russian \brief Сбросить таймер. \~english \brief Clear a timer. */
#define wait_time           bgrt_wait_time               /*!< \~russian \brief ПРограммная задержка. \~english \brief A software delay. */

#define CRIT_SEC_ENTER      BGRT_CRIT_SEC_ENTER          /*!< \~russian \brief Начало критической секции. \~english \brief A criyical section start. */
#define CRIT_SEC_EXIT       BGRT_CRIT_SEC_ENXIT          /*!< \~russian \brief Конец критической секции. \~english \brief A critical section end. */

#define status_t            bgrt_st_t                    /*!< \~russian \brief Тип возвращаемых статусов. \~english \brief An execution status type. */

//Sync primitives
#include "ipc.h"
#include "sem.h"
#include "mutex.h"
#include "cond.h"
#include "sig.h"

#endif // _NATIVE_H_
