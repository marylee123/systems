notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile parse: main.o parse.o
	@gcc -o parse parse.o main.o
main.o: main.c parse.h 
	@gcc -c main.c
parse.o: parse.c
	@gcc -c parse.c
run: parse
	@./parse
clean:
	rm *.o
	rm -f parse
