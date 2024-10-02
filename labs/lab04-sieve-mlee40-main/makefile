notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile sieve: driver.o sieve.o 
	@gcc -o sieve sieve.o driver.o -lm
driver.o: driver.c sieve.h
	@gcc -c driver.c
sieve.o: sieve.c
	@gcc -c sieve.c -lm
run: sieve
	@./sieve
clean:
	rm *.o
	rm -f sieve
