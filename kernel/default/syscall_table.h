BGRT_SC_TBL_ENTRY( PROC_RUN            ) /*!< \~russian \brief Запуск процесса.                                              \~english \brief A process launch.                                 */
BGRT_SC_TBL_ENTRY( PROC_RESTART        ) /*!< \~russian \brief Перезапуск процесса.                                          \~english \brief A Process restart.                                */
BGRT_SC_TBL_ENTRY( PROC_STOP           ) /*!< \~russian \brief Останов процесса.                                             \~english \brief A process stop.                                   */
BGRT_SC_TBL_ENTRY( PROC_SELF_STOP      ) /*!< \~russian \brief Самоостанов процесса.                                         \~english \brief A process self stop.                              */
BGRT_SC_TBL_ENTRY( PROC_TERMINATE      ) /*!< \~russian \brief Завершение работы процесса.                                   \~english \brief A process termination.                            */
BGRT_SC_TBL_ENTRY( PROC_LOCK           ) /*!< \~russian \brief Установить флаг #BGRT_PROC_FLG_LOCK для вызывающего процесса. \~english \brief #BGRT_PROC_FLG_LOCK for caller process.           */
BGRT_SC_TBL_ENTRY( PROC_FREE           ) /*!< \~russian \brief Останов процесса по флагу #BGRT_PROC_FLG_PRE_STOP.            \~english \brief #BGRT_PROC_FLG_PRE_STOP flag processing.          */
BGRT_SC_TBL_ENTRY( PROC_RESET_WATCHDOG ) /*!< \~russian \brief Сброс watchdog процесса реального времени.                    \~english \brief A real time process watchdog reset.               */
BGRT_SC_TBL_ENTRY( PROC_SET_PRIO       ) /*!< \~russian \brief Установить приоритет процесса                                 \~english \brief Set a process priority.                           */
BGRT_SC_TBL_ENTRY( PROC_GET_PRIO       ) /*!< \~russian \brief Получить приоритет процесса                                   \~english \brief Get a process priority.                           */
BGRT_SC_TBL_ENTRY( PROC_GET_ID         ) /*!< \~russian \brief Установить приоритет процесса                                 \~english \brief Set a process priority.                           */

BGRT_SC_TBL_ENTRY( SCHED_PROC_YELD     ) /*!< \~russian \brief Передача управления другому процессу.                         \~english \brief Transfer control to another process.              */

BGRT_SC_TBL_ENTRY( SYNC_SET_OWNER      ) /*!< \~russian \brief Установить нового хозяина объекта типа #bgrt_sync_t.          \~english \brief Set new #bgrt_sync_t object owner.                */
BGRT_SC_TBL_ENTRY( SYNC_GET_OWNER      ) /*!< \~russian \brief Узнать принадлежность объекта типа #bgrt_sync_t.              \~english \brief Get #bgrt_sync_t object owner.                    */
BGRT_SC_TBL_ENTRY( SYNC_OWN            ) /*!< \~russian \brief Завладеть объектом типа #bgrt_sync_t.                         \~english \brief Own #bgrt_sync_t object.                          */
BGRT_SC_TBL_ENTRY( SYNC_TOUCH          ) /*!< \~russian \brief Заблокировать пробуждение процессов.                          \~english \brief Block process wake.                               */
BGRT_SC_TBL_ENTRY( SYNC_SLEEP          ) /*!< \~russian \brief Заблокировать процесс в ожидании синхронизации.               \~english \brief Block process for synchronization.                */
BGRT_SC_TBL_ENTRY( SYNC_WAKE           ) /*!< \~russian \brief Запустить процесс, ожидающий синхронизации.                   \~english \brief Run a process waiting for synchronization.        */
BGRT_SC_TBL_ENTRY( SYNC_WAIT           ) /*!< \~russian \brief Подождать блокировки процесса на объекте типа #bgrt_sync_t.   \~english \brief Wait for process to block on #bgrt_sync_t object. */
BGRT_SC_TBL_ENTRY( SYNC_PROC_TIMEOUT   ) /*!< \~russian \brief Разбудить процесс по таймауту.                                \~english \brief Wake a process on timeout.                        */

BGRT_SC_TBL_ENTRY( USER                ) /*!< \~russian \brief Пользовательский системный вызов.                             \~english \brief User system call.                                 */
