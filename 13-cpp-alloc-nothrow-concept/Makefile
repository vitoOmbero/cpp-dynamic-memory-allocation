CC=g++

DEBUG=-g

LIBSRCDIR = ./shared_lib_src
LIBSRCDIR_STAT = ./client_src

CFLAGS=-c -Wall -Werror -Wpedantic -std=c++17 $(DEBUG)

LDFLAGS= -Wall -std=c++17 $(DEBUG)

DFLAGS= -DPTRS_ONLY

SONAME=libresprov.so.1
REAL_NAME=libresprov.so.1.0.0

all: exe resprov ln check run_test 

ln: ${REAL_NAME}
	-ln -s ${REAL_NAME} ${SONAME}

resprov: ${LIBSRCDIR}/resprov.cpp
	${CC} -shared -fPIC ${LDFLAGS} -Wl,-soname,${SONAME} -o ${REAL_NAME} ${LIBSRCDIR}/resprov.cpp

main.o: main.cpp
	${CC} ${CFLAGS} main.cpp 

rescons.o: $(LIBSRCDIR_STAT)/rescons.cpp
	${CC} ${CFLAGS} ${DFLAGS} ${LIBSRCDIR_STAT}/rescons.cpp

exe: main.o rescons.o
	${CC} ${LDLAGS} -Wl,-rpath,. -Wl,-rpath,$(LIBSRCDIR) main.o rescons.o -o test.out -ldl

clean:
	-rm -rf *.o *.so *.so.* *.out 2>/dev/null

run_test: test.out 
	./execute_test.sh

check:
	ldd test.out
	readelf -d libresprov.so.1

.PHONY: clean all run_test check ln
