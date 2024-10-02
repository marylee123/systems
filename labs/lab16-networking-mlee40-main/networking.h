#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h> 
#include <netdb.h>

#ifndef NETWORKING_H
#define NETWORKING_H
#define PORT "19230"
#define BUFFER_SIZE 1024

#define WKP "mario"

#define HANDSHAKE_BUFFER_SIZE 10
#define MAX_CLIENTS 100

#define SYN 0
#define SYN_ACK "Beware the Ides of March"
#define ACK "Et tu, Brute?"
#define MESSAGE 3
#define EXIT 4


void err(int i, char*message);
int server_setup();
int client_tcp_handshake(char*server_address);
int server_tcp_handshake(int listen_socket);
char *process(char *input);
#endif
