#include <exception>
#include <iostream>
#include <thread>

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

void NewHandler()
{
    static int c = 0;
    std::cout << "Failed to allocate memory (" << c++ << ")" << std::endl;
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    std::cout << "...// some logic, wait or clear resourses..." << std::endl;
    if (c == 6)
    {
        std::cout
            << "...// in this scenario we can't wait more and we are falling"
            << std::endl;
        std::terminate();
    }
}

int main(/*int argc, char* argv[]*/)
{
    std::set_new_handler(NewHandler);

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
