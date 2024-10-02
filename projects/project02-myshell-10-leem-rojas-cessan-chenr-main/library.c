#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


int err(){
    printf("errno %d, %s\n",errno, strerror(errno));
    exit(1);
}

/**
parse_args
arguments: line -> string of input from terminal
           arg_ary -> array of strings of command and flags so that it can be used in execvp
return: void -> only modifies arg_ary
purpose: to process data from stdin so that it can be exectued in shell
**/
int parse_args( char * line, char * parse_by, char ** arg_ary ) {
    if (line[strlen(line)-1] == '\n' || line[strlen(line)-1] == '\r') {
        line[strlen(line)-1] = '\0';
    }
    int i = 0;
    char * token;
    while (line){
        token = strsep(&line, parse_by);
        arg_ary[i] = token;
//        printf("cmd: %s\n", token);
        i++;
    }
    arg_ary[i]=NULL;
    return i;
}

/*
 cd_cmd() implements cd command
 return value: void
 arguments: a char*, which is where the user wants to change directory to
 */
void cd_cmd(char * change_dir) {
    // getting directory path from current directory
    if (change_dir != NULL) {
        char * PATH = (char*)malloc(256);
        if (getcwd(PATH, 256) != NULL) {
            snprintf(PATH, 256, "%s/%s/", PATH, change_dir);
            
            //changing directory to change_dir
            if (chdir(PATH) == 0) {
                // checking if directory actually changed
                if (getcwd(PATH, 256) != NULL) {
                } else err();
            } else err();
        } else err();
        free(PATH);
    }
}

/*
 redirect_stdout() redirects stdout of a program to a file
 return value: void
 arguments: a char**, which holds (one of the) command(s) made by user that includes ">" and has been parsed by " "
            a char*, which holds the name of the file the user wants to hold the stdout of the program
 */
void redirect_stdout(char ** temp, char *filename) {
    int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file == -1) err();
    int backup_stdout = dup( STDOUT_FILENO ); // save stdout for later
    dup2(file, STDOUT_FILENO); //sets STDOUT_FILENO's entry to the file for file
    close(file);
    pid_t pid = fork();
    if (pid == 0) {
        execvp(temp[0], temp);
    }
    else if (pid > 0) {
        //goes back to parent after child end
        int status;
        pid_t wpid = wait(&status);
        if (wpid == -1) err();
    }
    else err();
    fflush(stdout);//not needed when a child process exits, because exiting a process will flush automatically.
    dup2(backup_stdout, STDOUT_FILENO);
}

/*
 redirect_stdin() redirects stdin from a file to a program
 return value: void
 arguments: a char**, which holds (one of the) command(s) made by user that includes "<" and has been parsed by " "
            a char*, which holds the name of the file the user wants to act as the stdin for the program
 */
void redirect_stdin(char ** temp, char *filename) {
    int file = open(filename, O_RDONLY);
    if (file == -1) err();
    int backup_stdin = dup( STDIN_FILENO ); // save stdout for later
    dup2(file, STDIN_FILENO); //sets STDOUT_FILENO's entry to the file for file
    close(file);
    pid_t pid = fork();
    if (pid == 0) {
        execvp(temp[0], temp);
    }
    else if (pid > 0) {
        //goes back to parent after child end
        int status;
        pid_t wpid = wait(&status);
        if (wpid == -1) err();
    }
    else err();
    dup2(backup_stdin, STDIN_FILENO);
}

/*
 checkforspecialcharacters() checks if the input has special characters ("|", ">", "<"), to be used in executer()
 return value: int, which is determined based on the existence of special characters in the input
 arguments: a char**, which holds (one of the) command(s) made by user, and has been parsed by " "
 */
int checkforspecialcharacters(char ** args){
    int val = -1;
    int i = 0; // position
    while (args[i] != NULL){
        if (strncmp(args[i], "|", 1)==0){ // piping must take priority
            return 0;
        }
        if (strcmp(args[i], "<")==0){
            val = 1;
        }
        if (strcmp(args[i], ">")==0){
            val = 2;
        }
        i++;
    }
    return val;
}

/*
 executer() takes one command (separated from other commands by ";", and parsed by " " in main), and executes the command. It checks if the command has special characters such as "|", ">", "<", or "cd" first, so it can implement the command accordingly.
 return value: void
 arguments: a char**, which holds (one of the) command(s) made by user, and has been parsed by " "
 */
void executer(char ** args){
    int val = checkforspecialcharacters(args);
    if(val == 0){ // command has "|"
        char **command1 = malloc(15*sizeof(char*));
        char **command2 = malloc(15*sizeof(char*));
        int i = 0;
        while(strcmp(args[i],"|")!=0){ // copying left side of pipe to separate array
            command1[i] = malloc(sizeof(char*));
            strcpy(command1[i], args[i]);
            i++;
        }
        command1[i] = NULL;
        i++;

        int j = 0;
        while(args[i]){ // copying right side of pipe to separate array
            command2[j] = malloc(sizeof(char*));
            strcpy(command2[j], args[i]);
            //printf("command2[%d]: %s\n",j,command2[j]);
            i++;
            j++;
        }
        command2[j] = NULL;
        
        char * filename; // used if either left or right side of pipe has an arrow
        char * temp_file = malloc(sizeof(char*));
        strcpy(temp_file, "temp.txt"); // temp file is used to pass information across the pipe
        int check_cmd1 = checkforspecialcharacters(command1);
        int check_cmd2 = checkforspecialcharacters(command2);

        i = 0;

        if(check_cmd1 == 1){
            char **program1 = malloc(20*sizeof(char*)); // malloc space for program in command1
            while(strcmp(command1[i],"<")!=0){ // looping through command1 until "<" so that program1 has only program strings
                program1[i] = malloc(sizeof(char*));
                strcpy(program1[i], command1[i]);
                i++;
            }
            program1[i] = NULL;
            strcpy(filename, command1[i+1]); // last element of command1 will be filename

            int file = open(filename, O_RDONLY);
            if (file == -1) err();
            int backup_stdin = dup( STDIN_FILENO ); // save stdout for later
            dup2(file, STDIN_FILENO); //sets STDOUT_FILENO's entry to the file for file
            close(file);
            
            int temp = open(temp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644); // opening temp file to hold stdout
            if (temp == -1) err();
            int backup_stdout = dup( STDOUT_FILENO ); // save stdout for later
            dup2(temp, STDOUT_FILENO); //sets STDOUT_FILENO's entry to the file for file
            close(temp);
            
            int pid1 = fork();
            if (pid1 == 0) {
                execvp(program1[0], program1);
            }
            else if (pid1 > 0) {
                //goes back to parent after child end
                int status1;
                pid_t wpid1 = wait(&status1);
                if (wpid1 == -1) err();
            }
            else err();
            
            dup2(backup_stdin, STDIN_FILENO); // switch stdin back
            
            fflush(stdout);//not needed when a child process exits, because exiting a process will flush automatically.
            dup2(backup_stdout, STDOUT_FILENO); // switch stdout back
        }
        else{
            redirect_stdout(command1,temp_file);
        }

        if(check_cmd2 == 2){
            char **program2 = malloc(20*sizeof(char*)); // malloc space for program in command1
            i=0;
            while(strcmp(command2[i],">")!=0){ // looping through command2 until ">" so that program2 has only program strings
                program2[i] = (char*)malloc(sizeof(char*));
                strcpy(program2[i], command2[i]);
                i++;
            }
            program2[i] = NULL;
            strcpy(filename, command2[i+1]);
            
            int temp = open(temp_file, O_RDONLY);
            if (temp == -1) err();
            int backup_stdin = dup( STDIN_FILENO ); // save stdout for later
            dup2(temp, STDIN_FILENO); //sets STDOUT_FILENO's entry to the file for file
            close(temp);
            
            int file = open(filename, O_WRONLY | O_CREAT, 0644); // opening temp file to hold stdout
            if (file == -1) err();
            int backup_stdout = dup( STDOUT_FILENO ); // save stdout for later
            dup2(file, STDOUT_FILENO); //sets STDOUT_FILENO's entry to the file for file
            close(file);
            
            pid_t pid2 = fork();
            if (pid2 == 0) {
                execvp(program2[0], program2);
            }
            else if (pid2 > 0) {
                //goes back to parent after child end
                int status2;
                pid_t w2pid = wait(&status2);
                if (w2pid == -1) err();
            }
            else err();
             
            dup2(backup_stdin, STDIN_FILENO); // switch stdin back
            dup2(backup_stdout, STDOUT_FILENO); // switch stdout back
            fflush(stdout); //not needed when a child process exits, because exiting a process will flush automatically.
             
        }
        else{
            redirect_stdin(command2, temp_file);
        }
        remove(temp_file);
        exit(0);
    }
    else if(val == 1){ // command has "<" and no "|"
        char **program = malloc(sizeof(args));
        char *filename;
        int i = 0;
        while(strcmp(args[i],"<")!=0){
            program[i] = args[i];
            i++;
        }
        program[i] = NULL;
        filename = args[i+1];
        redirect_stdin(program,filename);
        exit(0);
    }
    else if(val == 2){ // command has ">" and no "|"
        
        char **program = malloc(sizeof(args));
        char *filename;
        int i;
        while(strcmp(args[i],">")!=0){
            program[i] = args[i];
            i++;
        }
        program[i] = NULL;
        filename = args[i+1];
        redirect_stdout(program,filename);
        exit(0);
    }
    else if (strcmp(args[0], "cd") == 0) {
        cd_cmd(args[1]);
        exit(0);
    }
    else{
        execvp(args[0],args);
        printf("%s: command not found\n", args[0]);
        exit(0);
    }
}
