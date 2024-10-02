notDefault:
	@echo "No arguments runs the first recipe no matter what you call it."
compile: controlStory writeStory
writeStory: write.o
	@gcc -o writeStory write.o
controlStory: control.o
	@gcc -o controlStory control.o
write.o: write.c
	@gcc -c write.c
control.o: control.c
	@gcc -c control.c
write: writeStory
	@./writeStory
control: controlStory
	@./controlStory $(ARGS)
clean:
	@rm *.o
	@rm writeStory
	@rm controlStory
