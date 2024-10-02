#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include "library.h"

int main(){
    pid_t thispid = getpid();
    //piping();
    while (1){
        printf("MyShell %% ");
        fflush(stdout);
        char line[256]; //buffer for stdin
        char * f = fgets(line, 256, stdin);
        //printf("line: %s\n", line); //testing fgets
        if (strchr(line, '\n')!=NULL){ //if token ends in newline
            *strchr(line, '\n')='\0'; //remove newline
        }
        //printf("line: %s\n", line); //testing fgets
        if (f==NULL){
            exit(0);
        }
        if (strncmp(line, "exit", 4) == 0){
          exit(0);
        }
        char * cmd[256];
        int c = parse_args(line, ";", cmd); //number of commands separated by ; not including the index of NULL
//        printf("c: %d\n", c); //testing correct number of command

        for (int i=0; i<c; i++) { //forking for every command
            if (strncmp(cmd[i], "exit", 4) == 0) exit(0);
            //            printf("cmd: %s\n", cmd[i]);
            char * args[256];
            int size_a = parse_args(cmd[i], " ", args); //parsing each sommand and getting total number of args
            
            if (strcmp(args[0], "cd") == 0) {
                cd_cmd(args[1]);
            }else{
                pid_t pid = fork();
                if (pid == 0) { //goes into child process to execute command
                    executer(args);
                }else if (pid > 0) {
                    //goes back to parent after child end
                    int status;
                    pid_t wpid = wait(&status);
                    int g = WEXITSTATUS(status);
                    //                printf("WEXIT %d", g);
                    if (g != 0){
                        // return 0;
                        exit(0);
                        //kill(thispid, SIGKILL);
                    }
                    if (wpid == -1) err();
                    //                printf("Main Process: %d; child: %d\n", getpid(), wpid);
                }else err();
            }
        }
    }
}
