#include <bitset>
#include <iostream>

#include "functions.h"

void PrintMemLittleEndian(const char* p1, const char* p2)
{
    for (char* p = const_cast<char*>(p1); p < p2; ++p)
    {
        char raw = *p;
        char rev = 0;
        for (auto i = 0; i < __CHAR_BIT__; ++i)
        {
            rev = rev << 1 | (raw & 1);
            raw >>= 1;
        }

        std::cout << std::bitset<8>(rev) << " ";
    }
    std::cout << std::endl;
}

void PrintMemBigEndian(const char* p2, const char* p1)
{
    for (char* p = const_cast<char*>(p2); p > p1; --p)
    {
        std::cout << std::bitset<8>(*p) << " ";
    }
    std::cout << std::endl;
}
