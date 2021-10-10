#include "solverApp.h"
#include "minmax.h"
#include <stdio.h>

int main(){
    
    int s_code[4] = {2, 1, 4, 5};
    int c2t_code[4] = {0, 0, 1, 1};
    int* oui_oui = minmax(s_code, c2t_code, 4, 6);

    printf("Took %d attempts to find code: [%d, %d, %d, %d]. \n", oui_oui[0], oui_oui[1], oui_oui[2], oui_oui[3], oui_oui[4]);
    free(oui_oui);
}