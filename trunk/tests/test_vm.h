#ifndef _TEST_VM_H_
#define _TEST_VM_H_

#define _TIME_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../include/bugurt.h"

// Команды тестовой виртуальной машины
#define TVM_NOP     0
#define TVM_LOOP    1
#define TVM_END     2

#define TVM_LLB     3
#define TVM_GLB     4

#define TVM_SWAIT1   5
#define TVM_SWAIT2   6
#define TVM_SSIG     7
#define TVM_SBRCST   8

#define TVM_SLOCK1   9
#define TVM_SLOCK2   10
#define TVM_SULOCK   11

#define TVM_MLOCK    12
#define TVM_MULOCK   13

typedef struct _test_vm
{
    int * pcounter; // счетчик программный
    int * pstart; // Указатель на начало "прогрраммы"
    int * loop_start; // Указатель на начало главного цикла программы
    char name[5];
}
test_vm_t;

void * test_vm( void * arg );

extern int idle_prorgam[];

// Инициация структуры _test_vm
void test_vm_init( test_vm_t * tvm, int * program, char * name);

void test_system_init(void);
void test_system_timer_interrupt(void);
void test_system_join(void);

#endif // _TEST_VM_H_
