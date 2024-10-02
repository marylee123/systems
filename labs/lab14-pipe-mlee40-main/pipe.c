#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>

#define READ 0
#define WRITE 1

int randomNum(int min, int max){
    int num = (rand() % (max + 1 - min) + min);
    return num;
}

char *process(char *input){ 
    if(input == NULL){
        return NULL;
    }
    char* output = malloc(sizeof(input)+1);
    strcpy(output, input);
    if(output != NULL){
        char* curr = output;
        while(*curr != '\0'){
        if((*curr >= 97 && *curr <= 122)){
            *curr -= 32;
        }
        curr++;
        }
    }
    return output;
}

int child(int pip[]){
    srand(time(NULL));
    char input[100];
    char *output;
    read(pip[READ], input, sizeof(input)); 
    pid_t p = fork();
    if(p < 0){
        perror("Fork failed\n");
        exit(1);
    }
    else if(p == 0){ 
        int fifo;
        int new_pid = getpid();
        float sleeper = randomNum(1, 1000000);
        printf("(%d) sleeping for %f sec\n", new_pid, sleeper/100000);
        usleep(sleeper); 
        fifo = open("fif", O_WRONLY);
        write(fifo, process(input), 100);
        close(fifo);
        exit(0);
    }
    return p;
}
