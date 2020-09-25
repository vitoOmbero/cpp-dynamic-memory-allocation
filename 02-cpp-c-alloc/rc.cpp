#include <iostream>

#include "functions.h"

#if defined(__linux__)
#include "malloc.h"
#endif

size_t sizemem(void* ptr)
{
#if defined(__linux__)
    return malloc_usable_size(ptr);
#else
#if defined(_WIN64) || defined(_WIN32)
    return _msize(ptr);
#else
    return 0;
#endif
#endif
}

void CStyleReinterpretCast(const int64_t val, const int64_t realloc_mem_size)
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
    std::cout << "RC-cast: " << *p << std::endl;

    PrintMemBigEndian(reinterpret_cast<char*>(p) + (char)7,
                      reinterpret_cast<char*>(p) - (char)1);

    std::cout << "Realloc:" << std::endl;
    std::cout << "Initial size: " << sizemem(p) << std::endl;
    p = reinterpret_cast<int64_t*>(realloc(p, realloc_mem_size));
    std::cout << "After realloc: " << sizemem(p) << std::endl;

    if (p == nullptr)
    {
        std::cout << "Failed to allocate memory!" << std::endl;
    }

    free(p);
}
