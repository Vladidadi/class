#ifndef PCBUFFER_H
#define PC

#include <pthread.h>
#include <semaphore.h>

#define PCBUFFER_SIZE 15

typedef struct {
    void *buffer [PCBUFFER_SIZE];
    pthread_mutex_t lock;
    sem_t used;
    sem_t free;
    int next_in;  //next available slot
    int next_out; //oldest used slot
} pcbuffer_t;

void pcbuffer_init(pcbuffer_t *);
void pcuffer_destroy(pcbuffer_t *);
void pcbuffer_push(pcbuffer_t *, void *value);
void *pcbuffer_pop(pcbuffer_t *);

#endif