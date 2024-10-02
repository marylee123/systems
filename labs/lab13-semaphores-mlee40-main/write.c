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
int main(){
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = SEM_UNDO;
    sb.sem_op = -1;

    int semd = semget(KEY, 1, 0);
    int shmid = shmget(SHMEM, sizeof(int), 0);
    semop(semd, &sb, 1);
    
    printf("Attempting to open resource...\n");

    int r_story = open("story.txt", O_RDONLY);
    if (r_story == -1){
        perror("Error: Cannot open file\n");
        exit(1);
    }

    int *file_size = shmat(shmid, 0, 0);
    if (*file_size == (off_t)-1){
        perror("Error: Cannot add shared memory\n");
        exit(1);
    }

    int pos = lseek(r_story, -(*file_size), SEEK_END);
    /*if (pos == -1){
        perror("Error: Cannot lseek file\n");
        exit(1);
    }*/

    char buffer[256];
    ssize_t bytes = read(r_story, buffer, sizeof(buffer) - 1);
    if (bytes == -1){
        perror("Error: Cannot read file\n");
        exit(1);
    }

    buffer[bytes] = '\0';
    printf("Last line added to the file: %s\n", buffer);
    if (*file_size == 0)

    printf("Next line to be added to the story: \n");
    fgets(buffer, sizeof(buffer), stdin);

    *file_size = strlen(buffer);

    close(r_story);


    int w_story = open("story.txt", O_WRONLY | O_APPEND);
    if (w_story == -1){
        perror("Error: Cannot open file\n");
        exit(1);
    }
    if (write(w_story, buffer, strlen(buffer)) == -1){
        perror("Error: Cannot write to file\n");
        exit(1);
    }

    sb.sem_op = 1;
    if (semop(semd, &sb, 1) == -1){
        perror("Error: Cannot release semaphore\n");
        exit(1);
    }

    close(w_story);

    return 0;
}
