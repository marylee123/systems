notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile pipe: main.o pipe.o
	@gcc -o pipe pipe.o main.o
main.o: main.c pipe.h
	@gcc -c main.c
pipe.o: pipe.c
	@gcc -c pipe.c
run: pipe
	@./pipe $(ARGS)
clean:
	rm *.o
	rm -f pipe
