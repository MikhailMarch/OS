#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include "sys/stat.h"

#define STR_SIZE 19

int main()
{
    struct stat buff;
	int file = open("ex1.txt", O_RDWR);
    char *new_str = "This is a nice day";
    fstat(file, &buff);
    size_t file_size = buff.st_size;
    unsigned char* f = (char*)mmap(0 , file_size , PROT_READ|PROT_WRITE,MAP_SHARED,file,0);
    for (int i=0;i<18;i++){
		f[i]=new_str[i];
	}
    for (int i = 18; i < file_size; i++) {
        f[i] = ' ';
    }
    munmap(f,18);
    close(file);
    return 0;
}