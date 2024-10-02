#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "structrw.h"
#include "entry.h"

int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-read_csv")==0){
        read_csv();
    }
    if(strcmp(argv[1], "-read_data")==0){
        read_data();
    }
    if(strcmp(argv[1], "-add_data")==0){
        printf("Enter year population borough: \n");
        char input[30];
        fgets(input, 30, stdin);
        add_data(input);
    }
    if(strcmp(argv[1], "-update_data")==0){
        read_data();
        
        int index;
        int year;
        int pop;
        char* boro = malloc(sizeof(char[15]));
        
        printf("Entry to update: \n");
        char input1[10];
        fgets(input1, 10, stdin);
        sscanf(input1, "%d", &index);
        
        printf("Enter year population borough: \n");
        char *input2 = malloc(sizeof(char[30]));
        fgets(input2, 30, stdin);

        sscanf(input2, "%d %d %s", &year, &pop, boro);
        
        update_data(index, year, pop, boro);
        
        read_data();
    }
    return 0;
}

