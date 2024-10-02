notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile euler:  main.o euler.o 
	@gcc -o euler  euler.o main.o
main.o: main.c euler.h
	@gcc -c main.c 
euler.o: euler.c  
	@gcc -c euler.c
run: euler
	@./euler
clean:
	rm *.o
	rm euler
