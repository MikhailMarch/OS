#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <memory.h>

int main() {
	struct stat srcStat;

	int file1 = open("ex1.txt", O_RDONLY);
	int file2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC);
    fstat(file1, &srcStat);
	ftruncate(file2, srcStat.st_size);
	char *file1map = (char *) mmap(0, srcStat.st_size, PROT_READ, MAP_SHARED, file1, 0);
	char *file2map = (char *) mmap(0, srcStat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file2, 0);

	memcpy(file2map, file1map, srcStat.st_size);

	munmap(file1map, srcStat.st_size);
	munmap(file2map, srcStat.st_size);
	close(file1);
	close(file2);

	return 0;
}