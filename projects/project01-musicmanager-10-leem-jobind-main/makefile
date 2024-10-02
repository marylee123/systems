compile linkedList: main.o linkedList.o library.o
	@gcc -o linkedList linkedList.o library.o main.o
main.o: main.c linkedList.h library.h
	@gcc -c main.c
linkedList.o: linkedList.c
	@gcc -c linkedList.c
library.o: library.c linkedList.h
	@gcc -c library.c
run: linkedList
	@./linkedList
clean:
	rm *.o
	rm -f linkedList

