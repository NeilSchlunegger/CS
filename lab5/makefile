CC=g++
CPPFLAGS= -Wall -g -std=c++11

main:	main.o supplied.o dlist.o

main.o:		dlist.h

dlist.o:	dlist.h

.PHONY: clean
clean:
		rm -rf app
		rm -rf main.o dlist.o
