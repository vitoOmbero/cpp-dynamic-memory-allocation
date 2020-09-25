#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void PrintMemLittleEndian(const char* p1, const char* p2);
void PrintMemBigEndian(const char* p2, const char* p1);

template <typename T>
void NewAlloc()
{
    T* p;
    PrintMemBigEndian(reinterpret_cast<char*>(p) + (char)(sizeof(T) - 1),
                      reinterpret_cast<char*>(p) - (char)1);
    p = new T;

    PrintMemBigEndian(reinterpret_cast<char*>(p) + (char)(sizeof(T) - 1),
                      reinterpret_cast<char*>(p) - (char)1);

#ifdef __linux__
    std::cout << "Likely, you see a zero/default value" << std::endl;
#endif
#if defined(_WIN64) || defined(_WIN32)
    std::cout << "Likely, you see a junk/default value" << std::endl;
#endif

    std::cout << "adr: " << p << std::endl;
    std::cout << "val: " << *p << std::endl;

    delete p;
}

template <typename T>
void NewObj()
{
    T* p;
    PrintMemBigEndian(reinterpret_cast<char*>(p) + (char)(sizeof(T) - 1),
                      reinterpret_cast<char*>(p) - (char)1);
    p = new T();

    PrintMemBigEndian(reinterpret_cast<char*>(p) + (char)(sizeof(T) - 1),
                      reinterpret_cast<char*>(p) - (char)1);
    std::cout << "You see a zero/default value" << std::endl;

    std::cout << "adr: " << p << std::endl;
    std::cout << "val: " << *p << std::endl;

    delete p;
}

template <typename T, const size_t length, class... U>
void NewArrObj(U&&... args)
{
    T* p;
    PrintMemBigEndian(reinterpret_cast<char*>(p) +
                          (char)(sizeof(T) * length - 1),
                      reinterpret_cast<char*>(p) - (char)1);
    p = new T[length]{ args... };

    PrintMemBigEndian(reinterpret_cast<char*>(&p[length]),
                      reinterpret_cast<char*>(&p[0]) - (char)sizeof(T));
    std::cout << "adr: " << p << std::endl;
    std::cout << "val: " << *p << std::endl;

    delete p;
}

template <typename T, const size_t length>
void NewArr()
{
    T* p;
    PrintMemBigEndian(reinterpret_cast<char*>(p) +
                          (char)(sizeof(T) * length - 1),
                      reinterpret_cast<char*>(p) - (char)1);
    p = new T[length];

    PrintMemBigEndian(reinterpret_cast<char*>(&p[length - 1]) +
                          (char)(sizeof(T)),
                      reinterpret_cast<char*>(&p[0]));
    std::cout << "You see a zero/default value" << std::endl;

    std::cout << "adr: " << p << std::endl;
    std::cout << "val: " << *p << std::endl;

    delete p;
}

#endif