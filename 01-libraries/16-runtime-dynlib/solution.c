#include <stddef.h>

int stringStat(const char* string, size_t multiplier, int* count)
{
    int         lenght = 0;
    const char* i      = string;
    for (; *i != '\0'; ++i)
        ++lenght;
    ++(*count);
    return lenght * multiplier;
}
