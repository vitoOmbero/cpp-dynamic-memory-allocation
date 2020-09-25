#include <iostream>

#include "functions.h"

void CStyleCCast(const int64_t val)
{
    int64_t* p;

    PrintMemBigEndian(reinterpret_cast<char*>(p) + (char)7,
                      reinterpret_cast<char*>(p) - (char)1);

    p = (int64_t*)(malloc(sizeof(int64_t)));

    if (p == nullptr)
    {
        std::cout << "Failed to allocate memory!" << std::endl;
    }

    PrintMemBigEndian(reinterpret_cast<char*>(p) + (char)7,
                      reinterpret_cast<char*>(p) - (char)1);

    *p = val;
    std::cout << "C-cast: " << *p << std::endl;

    PrintMemBigEndian(reinterpret_cast<char*>(p) + (char)7,
                      reinterpret_cast<char*>(p) - (char)1);

    free(p);
}
