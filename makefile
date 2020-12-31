# makefile

all:isort txtfind

isort: isort.o
	gcc -Wall isort.o -o isort

txtfind: txtfind.o
	gcc -Wall txtfind.o -o txtfind

isort.o: isort.c
	gcc -Wall -c isort.c -o isort.o

txtfind.o: txtfind.c
	gcc -Wall -c txtfind.c -o txtfind.o
	
.PHONY: clean all

clean: 
	rm *.o -f isort txtfind