CC=g++
CPPFLAGS= -Wall -g -std=c++11

main: main.o table.o supplied.o

main.o:	table.h

table.o: table.h

.PHONY: clean
clean:
	rm -rf main.o table.o
	rm -rf main
