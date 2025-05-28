build:
	gcc listlib.h listlib.c genlib.h genlib.c program.c -Wall
build-alt:
	gcc listlib.h listlib.c genlib.h genlib.c task4.c -Wall
add-git:
	git add listlib.h listlib.c genlib.h genlib.c program.c a.out
clean:
	rm -f a.out
run-example:
	./a.out ./in/data0.in ./out/data0.out
rm-git:
	git restore --staged listlib.h listlib.c genlib.h genlib.c program.c a.out