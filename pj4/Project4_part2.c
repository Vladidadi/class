#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sched.h>


int main(int argc, char* argv[]){

    printf("\n\nargc: %d, arg[0]: %s, arg[1]: %s",argc,argv[0],argv[1]);
    return 0;
}