#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h>

int main(){
for(int i = 0; i < 5;i++ ){
    fork();
}
 sleep(5);
return 0;
}

/*
tree for 3 repititions:
We start with process ex2 and each iteration instance of ex2 forks and creates new processes
at the end of execution we will have 8 processes.
─bash─┬─ex2─┬─ex2─┬─ex2───ex2
      │     │     └─ex2
      │     ├─ex2───ex2
      │     └─ex2
      └─pstree
tree for 5 repitions 
─bash─┬─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
      │     │     │     │     └─ex2
      │     │     │     ├─ex2───ex2
      │     │     │     └─ex2
      │     │     ├─ex2─┬─ex2───ex2
      │     │     │     └─ex2
      │     │     ├─ex2───ex2
      │     │     └─ex2
      │     ├─ex2─┬─ex2─┬─ex2───ex2
      │     │     │     └─ex2
      │     │     ├─ex2───ex2
      │     │     └─ex2
      │     ├─ex2─┬─ex2───ex2
      │     │     └─ex2
      │     ├─ex2───ex2
      │     └─ex2
      └─pstree
*/
