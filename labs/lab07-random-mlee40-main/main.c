#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}
#define BUFFER_SIZE 4
int randomNum(){
    int r_file = open("/dev/random", O_RDONLY, 0);
    int buff;
    read(r_file, &buff, BUFFER_SIZE);
    if(r_file == -1) err();
    close(r_file);
    return buff;
}
int main(){
    printf("Generating random numbers\n");
    
    int x = randomNum();
    int y = randomNum();
    printf("\tx: %d\n",x);
    printf("\ty: %d\n",y);

    int ary1[8];
    for(int i = 0; i < 8; i++){
        ary1[i] = randomNum();
        printf("\tary1[%d]: %d\n",i,ary1[i]);
    }
    
    printf("Writing numbers to file...\n");
    int w_file = open("write_file", O_WRONLY | O_CREAT, 0611);
    if(w_file == -1) err();
    write(w_file, &x, BUFFER_SIZE);
    write(w_file, &y, BUFFER_SIZE);
    write(w_file, &ary1, BUFFER_SIZE*8);
    close(w_file);
    
    printf("Reading numbers from file...\n");
    int r_file = open("write_file", O_RDONLY, 0);
    if(r_file == -1) err();
    int a;
    read(r_file, &a, BUFFER_SIZE);
    int b;
    read(r_file, &b, BUFFER_SIZE);
    int ary2[8];
    read(r_file, &ary2, BUFFER_SIZE*8);
    
    printf("Verification that written values were the same:\n");
    printf("\ta: %d\n",a);
    printf("\tb: %d\n",b);
    for(int i = 0; i < 8; i++){
        ary1[i] = randomNum();
        printf("\tary2[%d]: %d\n",i,ary2[i]);
    }
    
    close(r_file);

    return 0;
}
