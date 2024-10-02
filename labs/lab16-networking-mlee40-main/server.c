#include "networking.h"
void subserver_logic(int client_socket){
    char og_string[BUFFER_SIZE];
    char new_string[BUFFER_SIZE];

    read(client_socket,og_string,BUFFER_SIZE-1);
    printf("Server reading from Client: %s\n",og_string);

    strcpy(new_string,process(og_string));
    send(client_socket,new_string,sizeof(new_string),0);
    close(client_socket);
    printf("Server sending to Client: %s\n",new_string);
}

int main(int argc, char *argv[] ) {
    int listen_socket = server_setup();
    int client_socket;
    while (1) {
        client_socket = server_tcp_handshake(listen_socket);

        int p = fork();
        if(p<0){
            perror("Forking error\n");
        } 
        else if(p==0){ //child
            subserver_logic(client_socket);
            close(client_socket);
        } 
        else{ //parent
            close(client_socket);
        }
    } 
}
