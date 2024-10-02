#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/sem.h>
#include <sys/shm.h>
#define KEY 35841
#define SHMEM 78934

union semun {
    int val;                  //used for SETVAL
    struct semid_ds *buf;     //used for IPC_STAT and IPC_SET
    unsigned short  *array;   //used for SETALL
    struct seminfo  *__buf;
};
/*struct sembuf {
  short sem_op;
  short sem_num;
  short sem_flag;
}; */

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}

int semd;
int shmid;


void c_create() {
    semd = semget(KEY, 1, IPC_CREAT | 0644);
    if (semd == -1) {
        perror("Error: Cannot create semaphore.\n");
        exit(1);
    }
    union semun us;
    us.val = 1;
    semctl(semd, 0, SETVAL, us.val);

    shmid = shmget(SHMEM, sizeof(off_t), IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("Error: Cannot create shared memory\n");
        exit(1);
    }

    int w_story = open("story.txt", O_CREAT | O_TRUNC, 0644);
    if (w_story == -1){
        perror("Error: Cannot open file\n");
        exit(1);
    }

    close(w_story);
}
void c_view() {
    int r_story = open("story.txt", O_RDONLY);
    if (r_story == -1){
        perror("Error: Cannot open file\n");
        exit(1);
    }

    char buffer[256];
    ssize_t bytes;

    while ((bytes = read(r_story, buffer, sizeof(buffer) - 1)) > 0){
        buffer[bytes] = '\0';
        printf("%s", buffer);
    }

    if (bytes == -1){
        perror("Error: Cannot read file\n");
        exit(1);
    }

    close(r_story);
}
void c_remove(){
    c_view();

    int semd = semget(KEY, 1, 0);
    int shmid = shmget(SHMEM, sizeof(int), 0);

    if (semctl(semd, IPC_RMID, 0) == -1){
        perror("Error: Cannot remove semaphore\n");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, 0) == -1){
        perror("Error: Cannot remove shared memory\n");
        exit(1);
    }
}
int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "create") == 0) {
        c_create();
    } else if (strcmp(argv[1], "view") == 0) {
        c_view();
    } else if (strcmp(argv[1], "remove") == 0) {
        c_remove();
    } else {
        printf("Bad command!\n");
    }
}

