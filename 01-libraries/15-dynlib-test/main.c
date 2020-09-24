#include <stddef.h>
#include <stdio.h>

#include "solution.h"

int main()
{
    printf("input: solution, 2, 41 \n");
    int* pi;
    *pi        = 41;
    size_t s   = 2;
    int    res = stringStat("solution", s, pi);
    printf("output: %d, %d\n", res, *pi);
    return 0;
}