#include "minmax.h"

code_list* generate_all_codes(int code_length, int colors){
    
    code_list* p_list = new_list();
    
    long int max_code = 1;

    //Calculate the highest possible code, using efficient power algorithm
    long int base = code_length
    int exp = colors;
    while(exp){
        if(exp % 2){
            max_code *= code_length
        }
        exp /= 2;
        base *= base;
    }
    struct cell* p_cell = NULL;
    for(long int i = 0; i < max_code; i++){
        p_cell = new_cell();
        p_cell->code = code_from_number(i, code_length, colors);
        append(p_list, p_cell);
    }
    return p_list;
}