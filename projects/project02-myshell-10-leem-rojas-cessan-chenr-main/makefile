notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile shell.out:  main.o library.o
	@gcc -o shell.out library.o main.o
main.o: main.c library.h
	@gcc -c main.c
library.o: library.c
	@gcc -c library.c
run: shell.out
	@./shell.out
clean:
#	@rm *o shell.out 2> /dev/null || true
	@rm -f *.o prog
	@rm -f shell.out
