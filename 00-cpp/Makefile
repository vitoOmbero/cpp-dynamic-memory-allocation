
CC=g++

DEBUG=-g

CFLAGS=-c -Wall -Werror -Wpedantic -std=c++17 $(DEBUG)

LDFLAGS= -Wall -std=c++11 $(DEBUG)

all: exe

exe: main.o factorial.o hello.o
	$(CC) $(LDFLAGS) main.o factorial.o hello.o -o exe.out

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

factorial.o: factorial.cpp
	$(CC) $(CFLAGS) factorial.cpp

hello.o: hello.cpp
	$(CC) $(CFLAGS) hello.cpp

clean:
	-rm -rf *.o *.so *.out 2>/dev/null

.PHONY: clean all
