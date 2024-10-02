notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile signals: main.o
	@gcc -o signals main.o
main.o: main.c
	@gcc -c main.c
run: signals
	@./signals
clean:
	rm *.o
	rm -f signals


