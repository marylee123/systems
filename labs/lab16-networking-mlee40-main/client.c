#include "networking.h"

void clientLogic(int server_socket){
  printf("Enter (1024 char max): ");
  char line[BUFFER_SIZE];
  //fflush(stdin);
  //fflush(stdout);
  //input
  fgets(line,sizeof(line),stdin);
  send(server_socket,line,sizeof(line),0);
  //read modified string
  read(server_socket,line,sizeof(line));
  printf("Client reading \"%s\" from server\n",line);
  close(server_socket);
}

int main(int argc, char *argv[] ) {
  char* IP = "127.0.0.1";
  if(argc>1){
    IP=argv[1];
  }
  while(1) {
    int server_socket = client_tcp_handshake(IP);
    printf("Client connected.\n");
    clientLogic(server_socket);
    sleep(1);
  }
}
