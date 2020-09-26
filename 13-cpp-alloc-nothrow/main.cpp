#include <iostream>

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

MyStruct* ptr[5]{};

int main(/*int argc, char* argv[]*/)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "i:" << i << std::endl;
        ptr[i] = new (std::nothrow) MyStruct[INT64_MAX * INT32_MAX / 10];
        if (ptr[i] == nullptr)
        {
            std::cout << "Failed to allocate memory ;) " << std::endl;
            std::terminate();
        }
    }
    return 0;
}
