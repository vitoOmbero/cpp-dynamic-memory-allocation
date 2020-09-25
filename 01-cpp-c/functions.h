#ifndef FUNCTIONS_H
#define FUNCTIONS_H
using stdout_fptr = void (*)(const int);

void CStyleCCast(const int val, stdout_fptr print);
void CStyleStaticCast(const int val, stdout_fptr print);
void CStyleReinterpretCast(const int val, stdout_fptr print);

#endif
