#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_networking.h"
/*

static void sighandler(int signo) {
    if ( signo == SIGINT ){
      printf("Closing WKP...\n");
      remove(WKP);
      printf("WKP closed\n");
      exit(1);
    }
}
int main() {
    signal(SIGINT,sighandler);
    while(1){
        int to_client;
        int from_client;
        from_client = server_handshake(&to_client);

        //int subserver = server_connect(from_client);

        close(to_client);
        close(from_client);
        printf("****************\n");
    }
} */



/*notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile: basic_client.o pipe_networking.o basic_server.c persistant_server.c forking_server.c
	@gcc -o clientProcess basic_client.o pipe_networking.o 
	@gcc -c serverProcess basic_server.o persistant_server.o forking_server.o pipe_networking.o 
basic_client.o: basic_client.c pipe_networking.h
	@gcc -c basic_client.c
basic_server.o: basic_server.c pipe_networking.h
	@gcc -c basic_server.c 
persistant_server.o: persistant_server.c pipe_networking.h
	@gcc -c client Ppersistant_server.c
forking_server.o: forking_server.c pipe_networking.h
	@gcc -c forking_server.c
pipe_networking.o: pipe_networking.c pipe_networking.h
	@gcc -c pipe_networking.c
client: clientProcess
	@./clientProcess
server: serverProcess
	@./serverProcess
clean:
	@rm *.o
	@rm *~
    
    
    
    
    
clientProcess: basic_client.o pipe_networking.o
	gcc -o clientProcess basic_client.o pipe_networking.o 
serverProcess: basic_server.o persistant_server.o forking_server.o pipe_networking.o 
	gcc -o serverProcess basic_server.o persistant_server.o forking_server.o pipe_networking.o
    */