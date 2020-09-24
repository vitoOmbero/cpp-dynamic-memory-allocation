
all: executable

executable: main.c hello.h library
	gcc main.c -fPIC -L. -lhello -o hello.out

# -c flag set gcc to compile without calling ld
# change to gcc -shared hello.c -fPIC -o libhello.so
# and there is a static linking in fact
# check with:
# $: ldd hello.out
library: hello.h hello.c
	gcc -shared hello.c -fPIC -o libhello.so

clean:
	-rm hello.out libhello.so 2>/dev/null
	-rm *.o 2>/dev/null

