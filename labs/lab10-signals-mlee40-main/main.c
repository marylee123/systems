#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}
static void sighandler(int signo) {
    if ( signo == SIGINT ){
        char str[50];
        sprintf(str, "Process with PID: %d Exiting due to SIGINT", getpid());
        
        printf("%s\n", str);
        
        int a_file = open("output.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
        
        if(a_file == -1) err();
        write(a_file, str, 50);
        exit(1);
    }
    if ( signo == SIGQUIT ){
        printf("PPID: %d , PID: %d\n", getppid(), getpid());
    }
}
int main(){
    signal(SIGINT,sighandler);
    signal(SIGQUIT,sighandler);
    while(1){
        printf("%d\n",getpid());
        sleep(1);
    }
    return 0;
}

