#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>

typedef int (*solution_fptr_t)(const char*, size_t, int*);
int (*solution_fptr)(const char* string, size_t multiplier, int* count);

const char* libname = "./libsolution.so";
const char* symbol  = "stringStat";

typedef enum dynliberrc
{
    DYNLIBERRC_OK,
    DYNLIBERRC_HANDLE,
    DYNLIBERRC_FOOPTR
} dynliberrc;

dynliberrc init_libsolution()
{
    void* handle = dlopen(libname, RTLD_LAZY);
    if (NULL == handle)
        return DYNLIBERRC_HANDLE;

    solution_fptr = (solution_fptr_t)dlsym(handle, symbol);
    if (NULL == solution_fptr)
        return DYNLIBERRC_FOOPTR;

    return DYNLIBERRC_OK;
}

void print_err_msg(const dynliberrc errc)
{
    switch (errc)
    {
        case DYNLIBERRC_HANDLE:
            printf("Failed to init handle!\n");
            break;

        case DYNLIBERRC_FOOPTR:
            printf("Failed to init function pointer!\n");
            break;

        default:
            printf("Unexpected error code!\n");
            break;
    }
}

void run_test(solution_fptr_t foo_ptr)
{
    printf("input: solution, 2, 41 \n");
    int* pi;
    *pi        = 41;
    size_t s   = 2;
    int    res = foo_ptr("solution", s, pi);
    printf("output: %d, %d\n", res, *pi);
}

int main()
{
    dynliberrc errc = init_libsolution();

    if (DYNLIBERRC_OK == errc)
    {
        run_test(solution_fptr);
    }
    else
    {
        print_err_msg(errc);
    }

    return 0;
}