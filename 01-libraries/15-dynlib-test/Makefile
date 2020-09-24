
all:
	$(info "targets: run_one, run_two, clean")

default: run_two

solution_one: solution.h solution.c
	gcc -shared solution.c -fPIC -o libsolution.so

solution_two: solution.h solution2.c
	gcc -shared solution2.c -fPIC -o libsolution.so

exe: solution.h
	gcc main.c -fPIC -L. -lsolution -o test.out

clean:
	-rm libsolution.so 2>/dev/null
	-rm *.out 2>/dev/null

run_one: solution_one exe 
	./execute_test.sh

run_two: solution_two exe 
	./execute_test.sh
