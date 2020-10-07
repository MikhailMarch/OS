#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(){
    for(int i = 0; i < 10;i++){
    int * a = calloc(2560*sizeof(int));
    memset(a,0,sizeof(int)*2560);
    sleep(1);
    }
}


/*
programm uses RAM and when we allocate more and more memory it happens
that system starts to swap and "so" more than 0 while "si" increases
*/

/*
comment for ex3
when process starts amout of free memory becomes less
and when system is out of free memory is begins to swap
while running on my laptop process was on the third place

*/
