#include "pipe_networking.h"

int err(){
  printf("errno %d\n",errno);
  printf("%s\n",strerror(errno));
  exit(1);
}
 
/*=========================
  server_setup
  args:

  creates the WKP (upstream) and opens it, waiting for a  connection.
  removes the WKP once a connection has been made

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_setup() {
  int from_client = 0;

  printf("Server making the pipe\n");

  printf("Server opening the pipe\n");
  mkfifo(WKP, 0666);
  from_client = open(WKP, O_RDONLY);

  printf("Server removing the pipe\n");

  remove(WKP);

  return from_client;
}

/*=========================
  server_handshake
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  int from_client = server_setup();

  printf("Server reading SYN (the pid)\n");
  char private_name[50];
  read(from_client, private_name, 50);
  //printf("%s\n",private_name);

  printf("Server opening the Private Pipe\n");
  int pp = open(private_name, O_WRONLY);

  printf("Server sending SYN_ACK\n");
  write(pp, SYN_ACK, 50);

  printf("Server reading final ACK\n");
  char ack[50];
  read(from_client, ack, 50);

  if(strcmp(ack,ACK)==0){
    printf("Server received ACK, handshake complete\n");
  }

  return from_client;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  int from_server;

  char* private_name = calloc(50, sizeof(char));
  sprintf(private_name, "%d", getpid());

  printf("Client making Private pipe\n");

  printf("Client opening WKP\n");
  int wkp = open(WKP, O_WRONLY);

  printf("Client Writing PP to WKP\n");
  write(wkp, private_name, 50);
  //printf("pid: %s\n",private_name);

  printf("Client Opening PP\n");
  mkfifo(private_name, 0666);
  from_server = open(private_name, O_RDONLY);

  printf("Client Deleting PP\n");
  remove(private_name);

  printf("Client reading SYN_ACK\n");
  char syn_ack[50];
  read(from_server, syn_ack, 50);
  //printf("%s\n",syn_ack);
  printf("Client sending ACK\n");
  write(wkp, ACK, 50);
  
  while(1){
    char* og_string = "veni, vidi, vici";
    char new_string[50];
    write(wkp, og_string, 50);
    read(from_server, new_string, 50);
    printf("%s\n",new_string);
    //printf("hello\n");
    sleep(1);
  }

  close(from_server);
  return from_server;
}

/*=========================
  server_connect
  args: int from_client

  handles the subserver portion of the 3 way handshake

  returns the file descriptor for the downstream pipe.
  =========================*/
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
int server_connect(int from_client) {
  int to_client  = 0;

  printf("Server reading SYN (the pid)\n");
  char private_name[50];
  read(from_client, private_name, 50);
  //printf("%s\n",private_name);

  printf("Server opening the Private Pipe\n");
  to_client = open(private_name, O_WRONLY);

  printf("Server sending SYN_ACK\n");
  write(to_client, SYN_ACK, 50);

  printf("Server reading final ACK\n");
  char ack[50];
  read(from_client, ack, 50);

  printf("Server received ACK, handshake complete\n");

 while(1){
    char og_string[50];
    char new_string[50];
    read(from_client, og_string, 50);
    strcpy(new_string, process(og_string));
    write(to_client, new_string, 50);
    //printf("%s\n",new_string);
  }

  return to_client;
}


