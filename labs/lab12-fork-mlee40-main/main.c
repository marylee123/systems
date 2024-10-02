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
int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}
int randomNum(){
    int r_file = open("/dev/random", O_RDONLY, 0);
    int buff;
    read(r_file, &buff, 4);
    if(r_file == -1) err();
    close(r_file);
    return buff;
}
void child(){
    int random;
    random = abs(randomNum())%5+1;
    int pid = getpid();
    printf("Child! %d %dsec\n", pid,random);
    sleep(random);
    printf("Child! %d finished after %d seconds\n", pid,random);
}
int main(){
    srand(time(NULL));
    pid_t p;
    int parent_pid = getpid();
    printf("%d about to create 2 child processes\n", parent_pid);
    p = fork();
    if(p<0){
      perror("fork fail");//output to stderr instead of stdout
      exit(1);
    }if ( p == 0){
        child();
        exit(0);
    }
    else{
        pid_t q;
        q = fork();
        if(q<0){
            perror("fork fail");//output to stderr instead of stdout
            exit(1);
        }if(q == 0){
            child();
            exit(0);
        }
        wait(NULL);
        printf("Main Process %d is done.\n", parent_pid);
        exit(0);
    }
    return 0;
}

