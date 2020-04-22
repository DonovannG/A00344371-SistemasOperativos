#define NUMTHREADS 10
#include <stdio.h>
#include <pthread.h>

void * hello(void *id){
    printf("Hello world %ld\n", (long)id);
}

int main(){
    pthread_t hilos[NUMTHREADS];
    for (long i=0; i< NUMTHREADS; i++) {
        pthread_create(&hilos[i], NULL,hello,(void *)i);
    }
    pthread_exit(NULL);
}