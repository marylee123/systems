notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile structrw: main.o entry.o structrw.o
	@gcc -o structrw entry.o structrw.o main.o
main.o: main.c entry.h structrw.h
	@gcc -c main.c
entry.o: entry.c
	@gcc -c entry.c
structrw.o: structrw.c entry.h
	@gcc -c structrw.c
run: structrw
	@./structrw $(ARGS)
clean:
	rm *.o
	rm -f structrw
