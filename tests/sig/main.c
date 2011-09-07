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
    1,1,1,15,15,15,
    1,1,1,1,1,1
};
timer_t tq[12] =
{
    1,2,3,4,5,6,
    1,6,6,6,5,6
};

int glb_program[] =
{
    TVM_LOOP,
    TVM_GLB,
    TVM_END
};

// Нулевой сигнал будет будить 1 процесс
int sig_program[] =
{
    TVM_LOOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_SSIG, 0,
    TVM_END
};
// Первый сигнал будет будить весь список
int brc_program[] =
{
    TVM_LOOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_NOP,
    TVM_SBRCST, 1,
    TVM_END
};

int wt1_program[] =
{
    TVM_LOOP,
    TVM_SWAIT1, 1,
    TVM_SWAIT2, 1,
    TVM_END
};

int wt0_program[] =
{
    TVM_LOOP,
    TVM_SWAIT1, 0,
    TVM_SWAIT2, 0,
    TVM_END
};

int main()
{
    test_system_init();
    for(int i = 0; i < 12; i++)
    {
        char name[10];
        sprintf(name,"prc%d ",(int)i);
        test_vm_init(tvm + i,idle_prorgam,name);
        proc_init(proc+i,idle_main,0,0,tvm+i,0,pr[i],tq[i],rt[i],af[i]);
        proc_run(proc+i);
    }
    tvm[5].pstart = glb_program;
    tvm[5].pcounter = glb_program;

    tvm[4].pstart = sig_program;
    tvm[4].pcounter = sig_program;

    tvm[3].pstart = brc_program;
    tvm[3].pcounter = brc_program;

    //_proc_lres_inc(proc + 6);

    tvm[7].pstart = wt1_program;
    tvm[7].pcounter = wt1_program;

    tvm[8].pstart = wt1_program;
    tvm[8].pcounter = wt1_program;

    tvm[9].pstart = wt1_program;
    tvm[9].pcounter = wt1_program;

    // Ололо броадкастовые процессы!!!
    //tvm[0].pstart = wt0_program;
    //tvm[0].pcounter = wt0_program;

    tvm[1].pstart = wt0_program;
    tvm[1].pcounter = wt0_program;

    tvm[2].pstart = wt0_program;
    tvm[2].pcounter = wt0_program;

    for(int s = 0; s < 100; s++)
    {
        printf("\n----------------------------------\n");
        test_system_timer_interrupt();
    }
    proc[0].affinity = 15;
    proc[1].affinity = 15;
    proc[2].affinity = 15;
    proc[6].affinity = 9;

    proc[7].affinity = 15;
    proc[8].affinity = 15;
    proc[9].affinity = 15;
    proc[7].timer = proc[7].time_quant;
    proc[8].timer = proc[8].time_quant;
    proc[9].timer = proc[9].time_quant;
    proc_run(proc+7);
    proc_run(proc+8);
    proc_run(proc+9);

    proc[11].timer = proc[11].time_quant;
    proc_run(proc+11);
    printf("\n=========================================================\n");
    for(int s = 0; s < 100; s++)
    {
        printf("\n----------------------------------\n");
        test_system_timer_interrupt();
    }

    proc[1].affinity = 1;
    proc[2].affinity = 1;
    proc[7].timer = proc[7].time_quant;
    proc[8].timer = proc[8].time_quant;
    proc[9].timer = proc[9].time_quant;
    proc_run(proc+7);
    proc_run(proc+8);
    proc_run(proc+9);
    proc[7].flags |= PROC_FLG_PRE_END;
    proc[8].flags |= PROC_FLG_PRE_END;
    proc[9].flags |= PROC_FLG_PRE_END;
    printf("\n=========================================================\n");
    for(int s = 0; s < 100; s++)
    {
        printf("\n----------------------------------\n");
        test_system_timer_interrupt();
    }

    test_system_join();
    printf("%s", &"Hello world!\n");
    return 0;
}
