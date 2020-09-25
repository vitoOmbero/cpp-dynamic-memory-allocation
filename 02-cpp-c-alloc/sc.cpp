#include <iostream>

#include "functions.h"

void CStyleStaticCast(const int64_t val)
{
    int64_t* p;

    PrintMemLittleEndian(reinterpret_cast<char*>(p),
                         reinterpret_cast<char*>(p) + (char)8);

    p = static_cast<int64_t*>(calloc(1, sizeof(int64_t)));

    if (p == nullptr)
    {
        std::cout << "Failed to allocate memory!" << std::endl;
    }

    PrintMemLittleEndian(reinterpret_cast<char*>(p),
                         reinterpret_cast<char*>(p) + (char)8);

    *p = val;
    std::cout << "SC-cast: " << *p << std::endl;

    PrintMemLittleEndian(reinterpret_cast<char*>(p),
                         reinterpret_cast<char*>(p) + (char)8);

    free(p);
}
