#include <iostream>
#include <string>

#include "functions.h"

static int my_struct_next_id = 42;

struct MyStruct
{
    int id;
    MyStruct()
        : id{ my_struct_next_id++ }
    {
        PrintToStdout(": MyStuct Default ctor :");
    }
    MyStruct(int val)
        : id{ val }
    {
        PrintToStdout(": MyStuct Param(1) ctor :");
    }
    void PrintToStdout(const char* verbose)
    {
        std::cout << this << verbose << id << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const MyStruct& s)
{
    return stream << "Just MyStruct: " << s.id;
}

int main(/*int argc, char* argv[]*/)
{

    NewAlloc<int>();
    NewObj<int>();
    NewArr<int, 2>();
    NewArrObj<int, 2>(6, 7);

    std::cout << std::endl;

    NewAlloc<MyStruct>();
    NewObj<MyStruct>();
    std::cout << "====" << std::endl;
    NewArr<MyStruct, 2>();
    std::cout << "====" << std::endl;
    NewArrObj<MyStruct, 2>(6, 7);

    return 0;
}
