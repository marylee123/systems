notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile string: main.o mystring.o 
	@gcc -o string mystring.o main.o -lm
main.o: main.c mystring.h
	@gcc -c main.c
mystring.o: mystring.c
	@gcc -c mystring.c -lm
run: string
	@./string
clean:
	rm *.o
	rm -f string
