#ifndef _CONFIG_H_
// Тестовый конфиг-файл, в последствии будет заменен
#define _CONFIG_H_

#define WEAK __attribute__((__weak__))

// data types
typedef unsigned char index_t;
#define BITS_IN_INDEX_T (8)

typedef unsigned char prio_t;
typedef int * stack_t;

typedef unsigned int flag_t;

typedef unsigned int affinity_t;

typedef unsigned long load_t;

typedef unsigned long count_t;

#define timer_t unsigned long
//typedef unsigned long timer_t;

typedef volatile int lock_t;

typedef unsigned long bool_t;

typedef unsigned long core_id_t;

typedef struct _stat
{
    timer_t total_time_quant;
    count_t total_proc_count;
} stat_t;

typedef long signal_t;

// defines
#define CONFIG_USE_O1_SEARCH
#define CONFIG_USE_HIGHEST_LOCKER
#define MAX_CORES (4)
//#define CONFIG_USE_ALB
#define CONFIG_HARD_RT

#endif //_CONFIG_H_
