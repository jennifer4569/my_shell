all: shell.c main.c
	gcc -o run shell.c main.c

run: all
	./run
	
clean:
	rm run
	rm a.out
	rm *.o
	rm *~

