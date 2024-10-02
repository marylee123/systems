#include "networking.h"

void err(int i, char*message){
  if(i < 0){
	  printf("Error: %s - %s\n",message, strerror(errno));
  	exit(1);
  }
}

char *process(char *input){ 
  if(input == NULL){
    return NULL;
  }
  char* output = malloc(sizeof(input)-1);
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
/*Connect to the server
 *return the to_server socket descriptor
 *blocks until connection is made.*/
int client_tcp_handshake(char * server_address) {

  //getaddrinfo
  struct addrinfo * hints, * results;
  hints = calloc(1,sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM; //TCP socket
  hints->ai_flags = AI_PASSIVE; 
  results = calloc(1,sizeof(struct addrinfo));
  getaddrinfo(server_address, PORT, hints, &results); 


  int serverd;//store the socket descriptor here
  //create the socket
  
  //connect to the server
  
  serverd = socket(AF_INET,SOCK_STREAM,0);
  connect(serverd,results->ai_addr,results->ai_addrlen);


  free(hints);
  freeaddrinfo(results);

  return serverd;
}

/*Accept a connection from a client
 *return the to_client socket descriptor
 *blocks until connection is made.
 */
int server_tcp_handshake(int listen_socket){
  int client_socket;

  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);
  //accept the client connection
  client_socket = accept(listen_socket, (struct sockaddr*)&client_address,&sock_size);
  
  return client_socket;
}

/*Create and bind a socket.
* Place the socket in a listening state.
*/
int server_setup() {
  //setup structs for getaddrinfo
  struct addrinfo * hints, * results;
  hints = calloc(1,sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM; //TCP socket
  hints->ai_flags = AI_PASSIVE; 
  results = calloc(1,sizeof(struct addrinfo));
  getaddrinfo(NULL, PORT, hints, &results); 
  //create the socket
  int clientd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);//store the socket descriptor here
	
  //this code should get around the address in use error
  int yes = 1;
  int sockOpt =  setsockopt(clientd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
  err(sockOpt,"sockopt error");
  
  //bind the socket to address and port
  bind(clientd,results->ai_addr,results->ai_addrlen);
  //set socket to listen state
  listen(clientd,10);

  //free the structs used by getaddrinfo
  free(hints);
  freeaddrinfo(results);
  
  return clientd;
}
