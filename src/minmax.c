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
    while(cur_cell != NULL){
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

int max_score_code(int* code, code_list* p_list, int code_length, int colors){
    int size_hitc_arr = (code_length+1)*(code_length+2)/2;
    int hitc_array[size_hitc_arr];
    int score = 0;
    int s_hit = 0;
    int s_col = 0;
    int index = 0;
    int max_value = 0;
    for(int i = 0; i < size_hitc_arr; i++){
        hitc_array[i] = 0;
    }
    struct cell* cur_cell = p_list->first;
    while(cur_cell != NULL){
        score = play_guess(code, cur_cell->code, code_length, colors);
        s_col = score%(code_length+1);
        s_hit = score/(code_length+1);
        index = s_hit*(code_length+1) - s_hit*(s_hit-1)/2 + s_col;
        hitc_array[index] += 1;
        if(hitc_array[index] > max_value){
            max_value = hitc_array[index];
        }
        cur_cell = cur_cell->next;
    }

    return max_value;
}

int* next_code(code_list* p_wlist, code_list* p_alist, code_list* p_tcode, int code_length, int colors){
    struct cell* cur_cell = p_alist->first;
    struct cell* cur_cell2;
    int minmax_value = -1;
    int max = 0;
    bool tried;
    code_list minmax_set = {.first = NULL, .last = NULL, .length = 0};

    while(cur_cell != NULL){
        tried = true;
        cur_cell2 = p_tcode->first;
        while(cur_cell2 != NULL){
            for(int i = 0; i < code_length; i++){
                tried = tried && (cur_cell2->code[i] == cur_cell->code[i]);
            }
            if(tried){
                cur_cell2 = NULL;
            }else{
                cur_cell2 = cur_cell2->next;
            }
        }
        if(!tried){
            max = p_wlist->length - max_score_code(cur_cell->code, p_wlist, code_length, colors);
            if(max > minmax_value){
                minmax_value = max;
                minmax_set.length = 1;
                minmax_set.last = cur_cell;
                minmax_set.first = cur_cell;
            }else{
                if(max == minmax_value){
                    append(&minmax_set, cur_cell);
                }
            }
        }
        cur_cell = cur_cell->next;
    }
    //look for an element in p_wlist
    cur_cell = minmax_set.first;
    bool same_code;
    while(cur_cell != NULL){
        cur_cell2 = p_wlist->first;
        while(cur_cell2 != NULL){
            same_code = true;
            for(int i = 0; i < code_length; i++){
                same_code = same_code && (cur_cell->code[i] == cur_cell2->code[i]);
            }
            if(same_code){
                return cur_cell->code;
            }
            cur_cell2 = cur_cell2->next;
        }
        cur_cell = cur_cell->next;
    }
    return (minmax_set.first)->code;
}

int* minmax(int* s_code, int* c2t_code, int code_length, int colors){
    
    bool is_won = false;
    int nb_tries = 0;
    int* code2try = c2t_code;
    int score = 0;
    code_list* all_codes = generate_all_codes(code_length, colors);
    code_list* win_codes = generate_all_codes(code_length, colors);
    code_list* t_codes = new_list();
    struct cell* temp_cell;
    while(!is_won){
        score = play_guess(code2try, s_code, code_length, colors);
        nb_tries += 1;
        temp_cell = new_cell();
        temp_cell->code = code2try;
        append(t_codes, temp_cell);
        if(score == colors*(code_length+1)){
            is_won = true;
        }else{
            remove_codes(win_codes, code2try, score, code_length, colors);
            code2try = next_code(win_codes, all_codes, t_codes, code_length, colors);
        }
    }
    int* found_code_and_tries = malloc(sizeof(int)*(code_length+1));
    if(found_code_and_tries == NULL){
        printf("Error : cannot allocate memory to return found code in minmax \n");
    }
    found_code_and_tries[0] = nb_tries;
    for(int i = 0; i < code_length; i++){
        found_code_and_tries[i+1] = code2try[i];
    }
    free_list(all_codes);
    free_list(win_codes);
    free_list(t_codes);
    return found_code_and_tries;
}