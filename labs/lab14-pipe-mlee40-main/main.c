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
#include <stddef.h>
#include "pipe.h"

#define READ 0
#define WRITE 1

int main(){
    srand(time(NULL));
    char usr_input[100];
    int rand = randomNum(2,4);

    int pip[4][2];
    pipe(pip[0]);
    pipe(pip[1]);
    pipe(pip[2]);
    pipe(pip[3]);

    char* result[4];
    printf("Spawning %d worker threads.\n", rand);
    printf("User Control Program (%d) enter a line: \n", getpid());

    while(fgets(usr_input, 100, stdin)){ 
        srand(time(NULL));
        mkfifo("fif", 0666);
        int i = 0;
        while(i < rand){
            write(pip[i][WRITE], usr_input, 100);
            int p = child(pip[i]);
            char s[100];
            int fifo = open("fif", O_RDONLY);
            read(fifo, s, 100);
            result[i] = strtok(s, "\n");
            i++;
        }
        int j = 0;
        while(j < rand){
            printf("result %d: %s\n", j, result[j]);
            j++;
        }

        srand(time(NULL));
        rand = randomNum(2,4);
        printf("Spawning %d worker threads.\n", rand);
        printf("User Control Program (%d) enter a line: \n", getpid());
    }
}

