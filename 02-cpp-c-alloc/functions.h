#ifndef FUNCTIONS_H
#define FUNCTIONS_H
using stdout_fptr = void (*)(const int);

void CStyleCCast(const int64_t val);
void CStyleStaticCast(const int64_t val);
void CStyleReinterpretCast(const int64_t val,
                           const int64_t realloc_mem_size = sizeof(int64_t) *
                                                            20);

void PrintMemLittleEndian(const char* p1, const char* p2);
void PrintMemBigEndian(const char* p2, const char* p1);

#endif
