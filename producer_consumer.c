#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sched.h>
#include "pcbuffer.h"


pthread_cond_t is_full;
pthread_cond_t is_empty;


FILE *fp;
int readf(FILE *fp)
{
    // fp = popen("pwd","r");
    // char directory_check[512]="";
    // if(fp==NULL){
    //     printf("failed to run command");
    // }else{
    //     fgets(directory_check,sizeof(directory_check),fp);
    //     printf("\n current working directory is %s",directory_check);
    // }
	if((fp=fopen("message.txt", "r"))==NULL){
		printf("ERROR: can't open message.txt!\n");
		return 0;
	}
    // char item = getc(fp);
    // printf("\nproduced %c",item);
    //  item = getc(fp);
    // printf("\nproduced %c",item);
    //  item = getc(fp);
    // printf("\nproduced %c",item);
}

void* produce(pcbuffer_t *ring){

    if((fp=fopen("message.txt", "r"))==NULL){
		printf("ERROR: can't open message.txt!\n");
		return 0;
	}
    char item;
   do{
        item = getc(fp);
        if(item){
            pcbuffer_push(ring,&item);
           printf("\nproduced %c, buffer contains %s",item,(char*)ring->buffer);
        }else{
        printf("\nproduced EOF");
        }
    } while(item != EOF);  
    printf("\n End of File reached\n");
    

}

void* consume(pcbuffer_t *ring){
    char *item_ptr;
    do{
        item_ptr = pcbuffer_pop(ring);
        if(item_ptr){
        printf("\n<--------- consumed %c ",*item_ptr);

        }else{
        printf("\n<--------- consumed an EOF ");

        }
        
    }while(item_ptr !=NULL);
}
void* producer_thread(void* ring){
    pcbuffer_t *typecast_ring = (pcbuffer_t*) ring;
    produce(typecast_ring);
}

void* consumer_thread(void* ring){
    pcbuffer_t *typecast_ring = (pcbuffer_t*) ring;
    consume(typecast_ring);
}

int main(){
    
    readf(fp);

    pcbuffer_t* ring= malloc(sizeof(pcbuffer_t));
    pcbuffer_init(ring);
    pthread_t *producer_thread_instance;
    pthread_t *consumer_thread_instance;

    pthread_create(producer_thread_instance, NULL, (void *) producer_thread, ring); 
    pthread_create(consumer_thread_instance, NULL, (void *) consumer_thread, ring); 

    pthread_join(*producer_thread_instance,NULL);
    pthread_join(*consumer_thread_instance,NULL);
    return 0;
}
