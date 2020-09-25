#include <exception>
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

int* ptr[5]{};

int main(/*int argc, char* argv[]*/)
{
    try
    {
        for (int i = 0; i < 5; ++i)
        {
            std::cout << "i:" << i << std::endl;
            ptr[i] = new int[INT64_MAX * INT32_MAX / 10];
        }
    }
    catch (std::exception& ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
