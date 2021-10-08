#ifndef TOOLS_H
#define TOOLS_H
#include <stdlib.h>
#include <stdio.h>

int* code_from_number(long int num, int code_length, int colors);

long int number_from_code(int* p_code, int code_length, int colors);

#endif