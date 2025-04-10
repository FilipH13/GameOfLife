build:
	gcc listlib.h listlib.c genlib.h genlib.c program.c -Wall
add-git:
	git add listlib.h listlib.c genlib.h genlib.c program.c a.out
clean:
	rm -f a.out