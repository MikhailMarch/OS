#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
    for (int i = 0; i < 10; i++){
        void* a = malloc(2560*sizeof(int));
        memset(a, 2560*sizeof(int));
        struct rusage r;
        getrusage(RUSAGE_SELF, &r);
        printf("%d\n", r.ru_maxrss);
        sleep(1);        
    }
}