CC=g++
CPPFLAGS= -Wall -g -std=c++11

main:	main.o supplied.o clist.o

main.o:		clist.h

clist.o:	clist.h

.PHONY: clean
clean:
	rm -rf main
	rm -rf clist.o main.o
