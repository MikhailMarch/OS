#include <stdlib.h>
#include <stdio.h>

int* UserRealloc(int * a, int size_old, int size_new){
    if (a == NULL) return malloc(size_new);
    if(size_new == 0) {
        free(a);
        return NULL;
    }
    int* a1;
    if(size_old > size_new){
        a1 = malloc(sizeof(int)*size_new);
        for(int i = 0; i < size_new;i++){
            a1[i] = a[i];
        }
        free(a);
    } else {
        a1 = malloc(sizeof(int)*size_new);
        for(int i = 0; i < size_old;i++){
            a1[i] = a[i];
        }
        free(a);
    }
    return a1;
}

int main(){
    int* a = malloc(sizeof(int)*10);
    for(int i = 0; i < 10;i++){
        a[i] = 20;
    }
    int* b = UserRealloc(a, 10, 7);
    for(int i = 0; i < 7;i++){
        printf("%d ",b[i]);
    }
}