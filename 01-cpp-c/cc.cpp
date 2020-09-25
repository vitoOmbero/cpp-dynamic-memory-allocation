#include <cstdlib>

#include "functions.h"

void CStyleCCast(const int val, stdout_fptr print)
{
    int* p = (int*)(malloc(sizeof(int)));

    if (p == nullptr)
    {
        print(-0);
    }

    *p = val;

    print(*p);

    free(p);
}
