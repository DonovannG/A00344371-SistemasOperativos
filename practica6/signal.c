#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void processSignal(int s){
    printf("Recibi señal %d\n",s);
}

void processSignalE(int s){
    printf("Err: Can(not) be terminated\n");
}

int main(){
    signal(10, processSignal);
    signal(15, processSignalE);
    while(1){
        sleep(3);
        printf("Trabajando\n");
    }
    return 1;
}