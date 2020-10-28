#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char * s = "Hello";

if(!setvbuf(stdout, 0, _IOLBF, 0))
    for (int i = 0; i < 5; i++) {
        printf("%c", s[i]);
        sleep(1);
    }
}