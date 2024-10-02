notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile arrays: arrays.o
	@gcc -o arrays arrays.o
arrays.o: arrays.c 
	@gcc -c arrays.c 
run: arrays
	@./arrays
clean:
	rm *.o
	rm arrays
