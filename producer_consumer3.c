#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sched.h>
#include "pcbuffer2.h"



short debug =1;

FILE *fp;

void* producer_thread(void* ring){
    pcbuffer_t* typecast_ring = (pcbuffer_t*) ring;
    // produce(typecast_ring);
     if((fp=fopen("message.txt", "r"))==NULL){
		printf("ERROR: can't open message.txt!\n");
		return 0;
	}

  
    while(1){
          char *item;
        item = getc(fp);
        if(item && item != -1){
            pcbuffer_push(ring,(void*)item);
            printf("\nStored item %c\n",item);

        }else{
            puts("\n\nEND OF FILE\n\n");
            break;
        }
    }
}

void* consumer_thread(void* ring){
    pcbuffer_t* typecast_ring = (pcbuffer_t*) ring;
    char item;
    while(1){
        item=pcbuffer_pop(ring);
        printf("\nFound item %c\n",item);
    }
    // consume(typecast_ring);
}

int main(){
    
    pcbuffer_t* ring= malloc(sizeof(pcbuffer_t));
    pcbuffer_init(ring);
    pthread_t producer_thread_instance;
    pthread_t consumer_thread_instance;
    
    pthread_cond_init(&ring->free,NULL);
    pthread_cond_init(&ring->used,NULL);

    pthread_create(&producer_thread_instance, NULL, (void *) producer_thread, ring); 
    pthread_create(&consumer_thread_instance, NULL, (void *) consumer_thread, ring); 

    pthread_join(producer_thread_instance,NULL);
    pthread_join(consumer_thread_instance,NULL);
    return 0;
}
