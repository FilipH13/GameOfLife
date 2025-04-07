build:
	gcc genlib.h genlib.c program.c -Wall
clean:
	rm -f a.out