#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *directory = opendir("./tmp");


    char *file_name[255];
    unsigned long inode_number[255];
    struct dirent *entry;
    int found = 0;

    while ((entry = readdir(directory)) != NULL) {
        if(strcmp(entry->d_name, ".\0") == 0  || strcmp(entry->d_name, "..\0") == 0) continue;
        inode_number[found] = entry->d_ino;
        file_name[found] = entry->d_name;
        found++;
    }
    for (int i = 0; i < found; i++) {
        for (int j = i + 1; j < found; j++) {
            if (inode_number[j] != 0 && inode_number[j] == inode_number[i]) {
                printf("Hard linked files are %s, %s\n", file_name[i], file_name[j]);
                inode_number[j] = 0;
            }
        }
    }
    closedir(directory);
}