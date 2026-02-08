make:
	mkdir bin
	gcc main.c -o bin/main -lncurses
run:
	bin/main
clean:
	rm -r bin
	clear
prerequisites:
	sudo pacman -S ncurses