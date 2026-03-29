#include "pcbuffer.h"

void pcbuffer_init(pcbuffer_t *p){
    pthread_mutex_init(&p->lock,NULL);
    sem_init(&p->used,0,0);
    sem_init(&p->free,0,PCBUFFER_SIZE);
    p->next_in = 0;
    p->next_out = 0;
    
}

void pcbuffer_destroy(pcbuffer_t *p){
    pthread_mutex_destroy(&p->lock);
    sem_destroy(&p->used);
    sem_destroy(&p->free);
}

void pcbuffer_push(pcbuffer_t *p, void *value){
    sem_wait(&p->free);    //wait until there is a free spot
    pthread_mutex_lock(&p->lock);   //lock the mutex for the shared data
    p->buffer[p->next_in++] = value;    //insert the value in the buffer, incement
    if (p->next_in = PCBUFFER_SIZE) p->next_in = 0;     //if the buffer is full rollover index
    pthread_mutex_unlock(&p->lock);     //unlock
    sem_post(&p->used);     //signal used to wake consumer
}

void *pcbuffer_pop(pcbuffer_t *p){
    void *return_value;

    sem_wait(&p->used);
    pthread_mutex_lock(&p->lock);
    return_value = p->buffer[p->next_out++];
    if (p->next_out == PCBUFFER_SIZE) p->next_out = 0;
    pthread_mutex_unlock(&p->lock);
    sem_post(&p->free);
    return return_value;
}