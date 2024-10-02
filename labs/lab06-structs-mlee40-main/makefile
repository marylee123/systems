notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile node: main.o node.o
	@gcc -o node node.o main.o
main.o: main.c node.h
	@gcc -c main.c
node.o: node.c
	@gcc -c node.c
run: node
	@./node
clean:
	rm *.o
	rm -f node
