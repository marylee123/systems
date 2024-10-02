#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int is_reg_file(char * path){
    struct stat stat_buffer;
    stat(path,&stat_buffer);
    return S_ISREG(stat_buffer.st_mode);
}

int dir_size(DIR * dir){
    int size = 0;
    
    struct dirent *content = readdir(dir);
    
    struct stat stat_buffer;
    
    while(content != NULL){
        if(is_reg_file(content->d_name) != 0){
            stat(content->d_name,&stat_buffer);
            size += stat_buffer.st_size;
        }
        content = readdir(dir);
    }
    
    return size;
}
