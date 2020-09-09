#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(){
    char buf[100];
    while(1){
        printf("cmd ");
        fgets(buf, sizeof(buf), stdin);
        system(buf);
    }
}
