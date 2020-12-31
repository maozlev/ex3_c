# makefile

all: isort txtfind

isort.o: isort.c
	gcc -Wall -fPIC -c isort.c

txtfind.o: txtfind.c
	gcc -Wall -fPIC -c txtfind.c

clean:
	rm -f *.o *.a *.so isort txtfind
