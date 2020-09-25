#include <cstdlib>

#include "functions.h"

void CStyleStaticCast(const int val, stdout_fptr print)
{
    int* p = static_cast<int*>(malloc(sizeof(int)));

    *p = val;

    print(*p);

    free(p);
}
