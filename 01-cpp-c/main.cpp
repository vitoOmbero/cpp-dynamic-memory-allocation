#include <iostream>

#include "functions.h"

void print(const int val)
{
    std::cout << val << std::endl;
}

int main(/*int argc, char* argv[]*/)
{
    std::cout << "C-cast: ";
    CStyleCCast(INT16_MAX, print);
    std::cout << "RC-cast: ";
    CStyleReinterpretCast(INT16_MAX, print);
    std::cout << "SC-cast: ";
    CStyleStaticCast(INT16_MAX, print);

    return 0;
}
