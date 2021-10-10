#include "tools.h"

int* code_from_number(long int num, int code_length, int colors){

    int* p_code = malloc(sizeof(int)*code_length);
    if(p_code == NULL){
        printf("Error : cannot allocate memory for code in code_from_number");
    }
    long int a = num;
    int b = 0;
    for(int i = 0; i < code_length; i++){
        b = (int) a % colors;
        if(b < 0){
            b += colors;
        }
        p_code[code_length - 1 - i] = b;
        a = a/colors;
    }

    return p_code;
}

long int number_from_code(int* code, int code_length, int colors){
    long int num = 0;
    long int exp = 1;
    for(int i = 0; i < code_length; i++){
        num += exp * code[code_length - 1 - i];
        exp *= colors;
    }
    return num;
}

int play_guess(int* p_guess, int* p_code, int code_length, int colors){
    int colors_g[colors];
    int colors_c[colors];
    int hits = 0;
    int colors_hits = 0;
    for(int i = 0; i < colors; i++){
        colors_g[i] = 0;
        colors_c[i] = 0;
    }
    for(int i = 0; i < code_length; i ++){
        if(p_guess[i] == p_code[i]){
            hits += 1;
        }else{
            colors_g[p_guess[i]] += 1;
            colors_c[p_code[i]]  += 1;
        }
    }
    for(int i = 0; i < colors; i++){
        if(colors_g[i] < colors_c[i]){
            colors_hits += colors_g[i];
        }else{
            colors_hits += colors_c[i];
        }
    }

    return (code_length+1)*hits + colors_hits;
}