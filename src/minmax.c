#include "minmax.h"

code_list* generate_all_codes(int code_length, int colors){
    
    code_list* p_list = new_list();
    
    long int max_code = 1;

    //Calculate the highest possible code, using efficient power algorithm
    long int base = colors;
    int exp = code_length;
    while(exp){
        if(exp % 2){
            max_code *= base;
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

void remove_codes(code_list* p_list, int* p_guess, int score, int code_length, int colors){
    int cur_score = 0;
    struct cell* cur_cell = p_list->first;
    struct cell* temp_cell = NULL;
    while(cur_cell != p_list->last){
        cur_score = play_guess(p_guess, cur_cell->code, code_length, colors);
        if(cur_score != score){
            remove_cell(p_list, cur_cell);
            temp_cell = cur_cell;
            cur_cell = cur_cell->next;
            free_cell(temp_cell);
        }else{
            cur_cell = cur_cell->next;
        }
    }
}