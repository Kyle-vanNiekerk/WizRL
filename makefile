make:
	mkdir bin
	gcc main.c -o bin/main.o -lncurses
run:
	bin/main.o
clean:
	rm -r bin
prerequisites:
	sudo apt install libncurses5-dev libncursesw5-dev