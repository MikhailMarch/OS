#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* print_thread(void* ptr){
    int a = *(int*)ptr;
    printf("Thread number %d\n", a);
    pthread_exit(&a);
    return 0;
}


int main(){
    const int N = 3;
    pthread_t threads[N];
    for(int i =0; i < N; i++){
        printf("Thread have started: %d\n", i);
        int* t = malloc(sizeof(int));
        *t = i;
        pthread_create(&threads[i], NULL, print_thread, t);
        pthread_join(threads[i], NULL); 
        printf("Thread %d have finished\n", i); 
    }
    return 0;
}
