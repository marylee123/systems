notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile random: main.o
	@gcc -o random main.o
main.o: main.c
	@gcc -c main.c
run: random
	@./random
clean:
	rm *.o
	rm -f random

