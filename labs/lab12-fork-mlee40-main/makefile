notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile fork: main.o
	@gcc -o fork main.o
main.o: main.c
	@gcc -c main.c
run: fork
	@./fork
clean:
	rm *.o
	rm -f fork



