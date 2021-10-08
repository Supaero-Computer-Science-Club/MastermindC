#ifndef MINMAX_H
#define MINMAX_H
#include "code_list.h"
#include "tools.h"

code_list* generate_all_codes(int code_length, int colors);

void remove_codes(code_list* p_list, int* guess, int score, int code_length, int colors);

#endif