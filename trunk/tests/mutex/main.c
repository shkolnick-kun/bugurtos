#include "../test_vm.h"

proc_t proc[12];
test_vm_t tvm[12];

bool_t rt[12] =
{
    0,0,0,0,0,0,
    1,1,1,1,1,1
};

prio_t pr[12] =
{
    3,4,4,5,5,5,
    0,1,1,2,2,2
};
affinity_t af[12] =
{
    15,15,15,15,15,15,
    1,1,1,1,1,1
};
timer_t tq[12] =
{
    1,2,3,4,5,6,
    1,2,3,4,5,6
};

int glb_program[] =
{
    TVM_LOOP,
    TVM_GLB,
    TVM_END
};

int mutex_program[] =
{
    TVM_LOOP,
    TVM_MLOCK, 0,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_MLOCK, 1,
    TVM_NOP,
    TVM_MULOCK, 1,
    TVM_NOP,
    TVM_MULOCK, 0,
    TVM_END
};

int mutex_program2[] =
{
    TVM_LOOP,
    TVM_MLOCK, 0,
    TVM_NOP,
    TVM_MULOCK, 0,
    TVM_END
};

int main()
{
    int s,i;
    test_system_init();
    for(i = 0; i < 12; i++)
    {
        char name[10];
        sprintf(name,"prc%d ",(int)i);
        test_vm_init(tvm + i,idle_prorgam,name);
        proc_init(proc+i,idle_main,0,0,tvm+i,0,pr[i],tq[i],rt[i],af[i]);
        proc_run(proc+i);
    }
    tvm[4].pstart = glb_program;
    tvm[4].pcounter = glb_program;

    tvm[0].pstart = mutex_program;
    tvm[0].pcounter = mutex_program;
    tvm[1].pstart = mutex_program2;
    tvm[1].pcounter = mutex_program2;
    tvm[2].pstart = mutex_program2;
    tvm[2].pcounter = mutex_program2;

    //tvm[5].pstart = llb_program;
    //_proc_lres_inc(proc + 6,0);
    for(s = 0; s < 1000; s++)
    {
        printf("\n--------------------------------------\n");
        test_system_timer_interrupt();
    }
    test_system_join();
    printf("%s", &"Hello world!\n");
    return 0;
}