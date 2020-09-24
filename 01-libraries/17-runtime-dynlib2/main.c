#include <dlfcn.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*foo_ptr_t)(int);
int (*foo_ptr)(int);

void print_help()
{
    printf("Expected input:\n");
    printf("solution <lib.so> <function_symbol> <integer>\n\n");
}

bool is_help_token(char* token)
{
    return token == "-h" || token == "--help";
}

int main(int argc, char** argv)
{
    if (is_help_token(argv[1]))
    {
        print_help();
        return 0;
    }

    void* handle = dlopen(argv[1], RTLD_LAZY);

    if (NULL == handle)
        return -1;

    foo_ptr = (foo_ptr_t)dlsym(handle, argv[2]);

    int arg = atoi(argv[3]);

    int result = foo_ptr(arg);

    printf("%d\n", result);

    // comment next line, any difference?
    dlclose(handle);
    // https://stackoverflow.com/questions/24467404/dlclose-doesnt-really-unload-shared-object-no-matter-how-many-times-it-is-call

    return 0;
}