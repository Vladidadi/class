#include "pcbuffer2.h"
#include <string.h>
#include <stdlib.h>

void pcbuffer_init(pcbuffer_t *p){
    pthread_mutex_init(&p->lock,NULL);
    memset(p->buffer,0x00,sizeof(p->buffer));
    // sem_init(&p->used,0,0);
    // sem_init(&p->free,0,PCBUFFER_SIZE);
    p->next_in = 0;
    p->next_out = 0;
    
}

void pcbuffer_destroy(pcbuffer_t *p){
    pthread_mutex_destroy(&p->lock);
    // sem_destroy(&p->used);
    // sem_destroy(&p->free);
}

void pcbuffer_push(pcbuffer_t *p, void *value){

    pthread_mutex_lock(&p->lock);
    while(p->buffer[p->next_in]!=NULL){
        pthread_cond_wait(&p->free,&p->lock);

    }
    if(p->buffer[p->next_in]){
    }else{
        p->buffer[p->next_in]=(char*)value;
        p->next_in++;
        if(p->next_in==PCBUFFER_SIZE){
            p->next_in=0;
        }
    }
    pthread_mutex_unlock(&p->lock);
    pthread_cond_signal(&p->used);

    // sem_wait(&p->free);    //wait until there is a free spot
    // pthread_mutex_lock(&p->lock);   //lock the mutex for the shared data
    // p->buffer[p->next_in++] = *(char*)value;    //insert the value in the buffer, incement
    // if (p->next_in == PCBUFFER_SIZE) p->next_in = 0;     //if the buffer is full rollover index
    // pthread_mutex_unlock(&p->lock);     //unlock
    // sem_post(&p->used);     //signal used to wake consumer
}

char pcbuffer_pop(pcbuffer_t *p){



    char *return_value=malloc(sizeof(char));
        pthread_mutex_lock(&p->lock);
    while(p->buffer[p->next_out]==NULL){

        pthread_cond_wait(&p->used,&p->lock);
     
    }

    *return_value = (char)p->buffer[p->next_out];
    p->buffer[p->next_out]=0x00;
    p->next_out++;
    if(p->next_out==PCBUFFER_SIZE){
        p->next_out=0;
    }


        // }
     
    
    

    pthread_mutex_unlock(&p->lock);
    pthread_cond_signal(&p->free);


    // sem_wait(&p->used);
    // pthread_mutex_lock(&p->lock);
    // return_value = p->buffer[p->next_out++];
    // if (p->next_out == PCBUFFER_SIZE) p->next_out = 0;
    // p->buffer[p->next_out-1]=0x00;
    // pthread_mutex_unlock(&p->lock);
    // sem_post(&p->free);
    return *return_value;
}