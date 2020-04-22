#define NUMTHREADS 10
#include <stdio.h>
#include <pthread.h>

int val=5;
pthread_mutex_t mutex;

void * hello(void *id){
    printf("Hello world %ld\n", (long)id);
    pthread_mutex_lock(&mutex);
    val += val;
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t hilos[NUMTHREADS];
    for (long i=0; i< NUMTHREADS; i++) {
        pthread_create(&hilos[i], NULL,hello,(void *)i);
    }
    pthread_exit(NULL);
}