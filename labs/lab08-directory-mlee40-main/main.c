#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "directory.h"
int main(int argc, char *argv[]){
    char *path = malloc(sizeof(path));
    if(argc == 1){
        printf("Please enter a path: \n");
        char buffer[50];
        fgets(buffer, 15, stdin);
        sscanf(buffer, "%s", path);
    } else if(argc == 2){
        path = argv[1];
    }
    
    DIR * dir = opendir(path);
    struct dirent *content = readdir(dir);
    
    printf("\nStatistics for directory: \n");
    printf("Total Directory Size: %d Bytes\n", dir_size(dir));
    printf("\n");
    
    rewinddir(dir);
    printf("Directories:\n");
    while(content != NULL){
        if(is_reg_file(content->d_name) == 0){
            printf("\t%s\n", content->d_name);
        }
        content = readdir(dir);
    }

    printf("\n");
    rewinddir(dir);
    content = readdir(dir);
    printf("Regular Files:\n");
    while(content != NULL){
        if(is_reg_file(content->d_name) != 0){
            printf("\t%s\n", content->d_name);
        }
        content = readdir(dir);
    }
    printf("\n");
    
    closedir(dir);
}
