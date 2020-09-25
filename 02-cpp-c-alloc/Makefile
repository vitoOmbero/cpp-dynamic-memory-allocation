
CC=g++

DEBUG=-g

CFLAGS=-c -O0 -Wall -Werror -Wno-uninitialized -Wpedantic -std=c++17 $(DEBUG)

LDFLAGS= -Wall -std=c++11 $(DEBUG)

all: exe

exe: main.o rc.o cc.o sc.o print_mem.o
	$(CC) $(LDFLAGS) main.o rc.o cc.o sc.o print_mem.o -o exe.out

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

rc.o: rc.cpp
	$(CC) $(CFLAGS) rc.cpp

cc.o: cc.cpp
	$(CC) $(CFLAGS) cc.cpp

sc.o: sc.cpp
	$(CC) $(CFLAGS) sc.cpp

print_mem.o: print_mem.cpp
	$(CC) $(CFLAGS) print_mem.cpp

clean:
	-rm -rf *.s *.o *.so *.out 2>/dev/null

.PHONY: clean all
