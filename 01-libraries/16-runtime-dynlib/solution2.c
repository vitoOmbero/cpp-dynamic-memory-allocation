#include <stddef.h>

int stringStat(const char* string, size_t multiplier, int* count)
{
    int lenght = 0;
    while (*string != '\0')
    {
        ++string;
        ++lenght;
    }

    ++(*count);
    return lenght;
}
