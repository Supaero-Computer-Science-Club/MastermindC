#ifndef MINMAX_H
#define MINMAX_H
#include <stdlib.h>
#include "code_list.h"
#include "tools.h"

/**
 * @brief Generate all possible codes of a certain length, with a certain number of colors.
 *        
 * @details Each created code needs to be freed, and each cell also needs to be freed.
 * It is recommended to use the free_list function to do so.
 * 
 * @param code_length Length of codes
 * @param colors Number of colors in the codes
 * @return A pointer to a code list
 */
code_list* generate_all_codes(int code_length, int colors);

/**
 * @brief Remove all the codes from a list, that when played against a certain code,
 * do not produce a certain score.
 * 
 * @param p_list List in which to found the code
 * @param guess Code to play against
 * @param score Score
 * @param code_length Length of codes
 * @param colors Number of colors in the codes
 */
void remove_codes(code_list* p_list, int* guess, int score, int code_length, int colors);

/**
 * @brief Returns a certain number used in minmax algorithm, see details
 * 
 * @details The function counts for one code, for all scores, how many codes from
 * the list produce the score. It then return the max number of codes
 * 
 * 
 * @param code The code
 * @param p_list List of codes to play against
 * @param code_length Length of codes 
 * @param colors Numbers of colors in the codes
 * @return The number 
 */
int max_score_code(int* code, code_list* p_list, int code_length, int colors);

/**
 * @brief Returns the next code to try in minmax algorithm
 * 
 * @param p_wlist Pointer to the list of codes that can be the right ones
 * @param p_alist Pointer to the list of all possible codes
 * @param p_tcode Pointer to the list of codes that have already been tried
 * @param code_length Length of codes
 * @param colors Number of colors in the codes
 * @return An int array corresponding to the code.
 * 
 * @warning DO NOT FREE THE RETURNED CODE, IT WILL BE AUTOMATICALLY FREED WHEN YOU FREE p_wlist AND p_alist
 */
int* next_code(code_list* p_wlist, code_list* p_alist, code_list* p_tcode, int code_length, int colors);

/**
 * @brief Minmax algorithm to find number of tries.
 * 
 * @param s_code Secret code to be found
 * @param c2t_code First code to try
 * @param code_length Length of the codes
 * @param colors Number of colors in the code
 * @return An int array, such that the first element is the number of tries
 * it took to find the code, and the others element afterward are the found code. Needs to be freed.
 */
int* minmax(int* s_code, int* c2t_code, int code_length, int colors);

#endif