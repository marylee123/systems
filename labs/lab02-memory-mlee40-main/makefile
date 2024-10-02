notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile memory: memory.o
	@gcc -o memory memory.o
memory.o: memory.c 
	@gcc -c memory.c 
run: memory
	@./memory
clean:
	rm *.o
	rm memory
