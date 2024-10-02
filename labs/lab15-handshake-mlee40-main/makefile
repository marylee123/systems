notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile: basic_client.o basic_server.o persistant_server.o forking_server.o pipe_networking.o
	@gcc -o clientProcess basic_client.o pipe_networking.o
	@gcc -o serverProcess basic_server.o persistant_server.o forking_server.o pipe_networking.o
basic_client.o: basic_client.c pipe_networking.h
	@gcc -c basic_client.c
basic_server.o: basic_server.c pipe_networking.h
	@gcc -c basic_server.c 
persistant_server.o: persistant_server.c pipe_networking.h
	@gcc -c client persistant_server.c
forking_server.o: forking_server.c pipe_networking.h
	@gcc -c forking_server.c
pipe_networking.o: pipe_networking.c pipe_networking.h
	@gcc -c pipe_networking.c
client: clientProcess
	./clientProcess
server: serverProcess
	./serverProcess
clean:
	rm *.o
	rm -f clientProcess
	rm -f serverProcess