#include <cstdlib>

#include "functions.h"

void CStyleReinterpretCast(const int val, stdout_fptr print)
{
    int* p = reinterpret_cast<int*>(malloc(sizeof(int)));

    *p = val;

    print(*p);

    free(p);
}
