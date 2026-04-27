#define _GNU_SOURCE

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>
// #include <sys/time.h>
// #include <sys/param.h>
// #include <sched.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

/*
The module should take a process ID as the input, calculate and output the total size of
the process’s virtual address space in use.
*/
struct task_struct *task;
int args_needed=2;
int main(int argc, char* argv[]){

    printf("\n\nargc: %d, arg[0]: %s, arg[1]: %s",argc,argv[0],argv[1]);
    if(!argc==args_needed){
        return -1;
    }
    int process_pid=argv[1];
    task=current;
    printk(KERN_INFO "heres a task named %s with PID [%d] whose state is %s\n",task->comm , task->pid,print_state);


    return 0;
}