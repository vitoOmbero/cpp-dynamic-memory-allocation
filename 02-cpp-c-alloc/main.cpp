#include <bitset>
#include <iostream>

#include "functions.h"

void warming_up()
{
    for (int i = 0; i < 200; ++i)
    {
        int* p = (int*)malloc(200 * 1024 * 1024);
        free(p);
        std::cout << i;
    }
    std::cout << "ok" << std::endl;
}

int main(/*int argc, char* argv[]*/)
{
    warming_up();

    std::cout << "PrintMemLittleEndian" << std::endl;
    CStyleStaticCast(INT64_MAX);
    std::cout << std::endl;
    CStyleStaticCast(INT64_MIN);
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "PrintMemBigEndian" << std::endl;
    CStyleCCast(INT64_MAX);
    std::cout << std::endl;
    CStyleCCast(INT64_MIN);
    std::cout << std::endl;

    // malloc return zeroed memory on linux because of
    // https://en.wikipedia.org/wiki/Zero_page
    // but not all OS are linux...

    std::cout << "PrintMemBigEndian" << std::endl;
    CStyleReinterpretCast(INT64_MAX);
    std::cout << std::endl;
    CStyleReinterpretCast(INT64_MIN, INT64_MAX);
    std::cout << std::endl;

    return 0;
}
