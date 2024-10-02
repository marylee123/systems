#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "entry.h"

#define COLUMN_NUM 5
#define BUFFER_SIZE sizeof(struct pop_entry)

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}
void read_csv(){
    FILE *data;
    data = fopen("nyc_pop.csv", "r");
    if(data == NULL) err();

    int lineNum = -1;
    char *line = malloc(300);

    char **boroNames = calloc(COLUMN_NUM,sizeof(char*));
    for (int i = 0; i < COLUMN_NUM; i++){
        boroNames[i] = calloc(15, sizeof(char));
    }

    struct pop_entry **dataset = malloc(115*BUFFER_SIZE);
    
    while(fgets(line, 300, data) != NULL){
        char *s = line;
        while(*s){
            if(*s=='\n' || *s=='\r'){
                *s = '\0';
            }
            s++;
        }
        char*p = line;
        if(lineNum == -1){
            int i = 0;
            strsep(&p, ",");
            char *borough = strsep(&p, ",");
            while(borough != NULL){
                strcpy(boroNames[i], borough);
                borough = strsep(&p, ",");
                i++;
           }
       }
       else{
           int year; int pop;
           char *year_str = strsep(&p, ",");
           sscanf(year_str, "%d", &year);
           
           char *pop_str;
           int i = 0;
           while((pop_str = strsep(&p, ","))){
               int index = i+COLUMN_NUM*lineNum;
               sscanf(pop_str, "%d", &pop);
               dataset[index] = create_entry(year, pop, boroNames[i]);
               i++;
           }
           dataset[i+COLUMN_NUM*lineNum] = NULL;
       }
       lineNum++;
    }
    fclose(data);
    
    int w_file = open("nyc_pop.dat", O_WRONLY | O_CREAT | O_TRUNC, 0611);
    if(w_file == -1) err();

    int i = 0;
    while(dataset[i] != NULL){
        write(w_file, dataset[i], BUFFER_SIZE);
        i++;
    }

    close(w_file);
}

void read_data(){
    struct stat * stat_buffer;
    struct stat s_buff;
      
    stat_buffer = malloc(sizeof(struct stat));
      
    stat("./nyc_pop.dat", stat_buffer);
    
    struct pop_entry **dataset = malloc(stat_buffer->st_size);
    int r_file = open("nyc_pop.dat", O_RDONLY, 0);
    if(r_file == -1) err();
    
    int i = 0;
    
    int bytes;
    dataset[i] = malloc(BUFFER_SIZE);
    while((bytes = read(r_file, dataset[i], BUFFER_SIZE))){
        if(bytes == -1)err();
        printf("[%d]   ",i);
        print_entry(dataset[i]);
        i++;
        dataset[i] = malloc(BUFFER_SIZE);
    }
}

void add_data(char*input){
    int year;
    int pop;
    char *boro;
    struct pop_entry *entry = malloc(BUFFER_SIZE);
    
    sscanf(input, "%d %d %s", &year, &pop, boro);
    entry = create_entry(year, pop, boro);
    
    int a_file = open("nyc_pop.dat", O_WRONLY | O_APPEND, 0644);
    if(a_file == -1) err();
    
    write(a_file, entry, BUFFER_SIZE);
    printf("Appended data to file: ");
    print_entry(entry);
    
    close(a_file);
}

void update_data(int index, int year, int pop, char*boro){
    struct stat * stat_buffer;
    struct stat s_buff;
      
    stat_buffer = malloc(sizeof(struct stat));
      
    stat("./nyc_pop.dat", stat_buffer);
    
    struct pop_entry **dataset = malloc(stat_buffer->st_size);
    int i = 0;
    int size = (stat_buffer->st_size)/BUFFER_SIZE;
    //printf("%d\n",size);
    while(i < size){
        dataset[i] = malloc(BUFFER_SIZE);
        i++;
    }
    
    int r_file = open("nyc_pop.dat", O_RDONLY, 0);
    if(r_file == -1) err();
    
    i = 0;

    
    int bytes;
    while((bytes = read(r_file, dataset[i], BUFFER_SIZE))){
        if(bytes == -1)err();
        i++;
    }
    dataset[index] = create_entry(year, pop, boro);
    close(r_file);
    
    
    int w_file = open("nyc_pop.dat", O_WRONLY | O_TRUNC, 0);
    if(w_file == -1) err();
    
    i = 0;
    while(dataset[i] != NULL){
        write(w_file, dataset[i], BUFFER_SIZE);
        i++;
    }
    i = 0;
    while(dataset[i] != NULL){
        printf("%d     ",i);
        print_entry(dataset[i]);
        i++;
    }
    close(w_file);
}

