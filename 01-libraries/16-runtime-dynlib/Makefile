
run: run_one run_two exit

help:
	$(info "targets: run, run_one, run_two, clean")

solution_one: solution.c
	gcc -shared solution.c -fPIC -o libsolution.so

solution_two: solution2.c
	gcc -shared solution2.c -fPIC -o libsolution.so

exe: main.c
	gcc main.c -ldl -fPIC -L. -o test.out

clean:
	-rm libsolution.so 2>/dev/null
	-rm *.out 2>/dev/null

run_one: solution_one exe 
	./execute_test.sh

run_two: solution_two exe 
	./execute_test.sh

exit:
	ldd test.out
