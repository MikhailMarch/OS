#include <pthread.h>
#include <stdio.h>

char b[30];

int pos, consumer, producer;
long long int timer;

void* Consume(void* a){
    while(1){
        if(consumer != 0)
            continue; 
        if(pos == 0){
            consumer = 1;
            producer = 0;
            continue;
        }
        printf("%c", b[pos]);
        pos--;
    }
    pthread_exit(0);
    return 0;
}

void* Produce(void* a){
    while(1){
        if(consumer != 0)
            continue; 
        if(pos == 30){
            consumer = 0;
            producer = 1;
            printf("Production is done for %lld\n", timer++);
            continue;
        }
        b[pos] = 'a' + pos;
        pos++;
    }
    pthread_exit(0);
    return 0;
}

int main(){
    producer = 1;

    pthread_t tProd,tCons;
    pthread_create(&tProd,0,Produce,0);
    pthread_create(&tCons,0,Consume,0);
    while(1);
}
