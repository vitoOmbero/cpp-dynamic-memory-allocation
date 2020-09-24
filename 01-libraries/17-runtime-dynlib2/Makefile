
LIBSRCDIR = ./callees

all: exe run_one run_two

help:
	$(info "targets: all, run_one, run_two, clean")

callee_one: $(LIBSRCDIR)/foo.c
	gcc -shared $(LIBSRCDIR)/foo.c -fPIC -o libfoo.so

callee_two: $(LIBSRCDIR)/bar.c
	gcc -shared $(LIBSRCDIR)/bar.c -fPIC -o libbar.so

exe: main.c
	gcc main.c -ldl -Wl,-rpath,. -Wl,-rpath,./callees -o test.out

clean:
	-rm *.so 2>/dev/null
	-rm *.out 2>/dev/null

run_one: callee_one exe 
	./execute_test.sh

run_two: callee_two exe 
	./execute_test.sh

exit:
	ldd test.out
