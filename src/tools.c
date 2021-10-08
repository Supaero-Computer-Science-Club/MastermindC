#import "tools.h"

int* code_from_number(long int num, int code_length, int colors){

    int* p_code = malloc(sizeof(int)*code_length);
    if(p_code == NULL){
        printf("Error : cannot allocate memory for code in code_from_number");
    }
    long int a = num;
    int b = 0;
    for(int i = 0; i < code_length, i++){
        b = (int) num % colors;
        if(b < 0){
            b += colors;
        }
        a = num/colors;
        p_code[code_length - 1 - i] = b;
    }

    return p_code;
}

long int number_from_code(int* code, int code_length, int colors){
    long int num = 0;
    long int exp = 1;
    for(i = 0; i < code_length; i++){
        num += exp * code[code_length - 1 - i];
        exp *= colors;
    }
    return num;
}