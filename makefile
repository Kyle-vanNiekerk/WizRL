make:
	mkdir bin
	gcc main.c -o bin/main -lncurses
run:
	bin/main
clean:
	rm -r bin
	clear
prerequisites:
	sudo apt install libncurses5-dev libncursesw5-dev
testing:
	gcc test/test.c -o test/test
	test/test
	rm test/test