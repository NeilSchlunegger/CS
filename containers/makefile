# Project makefile

# Compiler options
CC=g++
FLAG=-g -std=c++11 -Wall -lgmpxx -lgmp -lgslcblas -lgsl -lm

# Project files
MODULES=main list set map
SOURCES=$(foreach mod,$(MODULES),$(mod).cpp)
HEADERS=$(foreach mod,$(MODULES),$(mod).h)
OBJECTS=$(foreach mod,$(MODULES),$(mod).o)

# Make targets
all:		main

main:	$(SOURCES) $(HEADERS)
		$(CC) $(FLAG) -o main $(SOURCES)

clean:
		rm -rf *.o main main.exe main.cpp~

