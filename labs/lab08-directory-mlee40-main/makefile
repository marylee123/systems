notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile directory: main.o directory.o
	@gcc -o directory directory.o main.o
main.o: main.c directory.h
	@gcc -c main.c
directory.o: directory.c
	@gcc -c directory.c
run: directory
	@./directory $(ARGS)
clean:
	rm *.o
	rm -f directory
