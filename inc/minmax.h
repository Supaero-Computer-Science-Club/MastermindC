#ifndef MINMAX_H
#define MINMAX_H
#include <stdlib.h>
#include "code_list.h"
#include "tools.h"

code_list* generate_all_codes(int code_length, int colors);

void remove_codes(code_list* p_list, int* guess, int score, int code_length, int colors);

int max_score_code(int* code, code_list* p_list, int code_length, int colors);

int* next_code(code_list* p_wlist, code_list* p_alist, code_list* p_tcode, int code_length, int colors);

int* minmax(int* s_code, int* c2t_code, int code_length, int colors);

#endif