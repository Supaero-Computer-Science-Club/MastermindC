#ifndef TOOLS_H
#define TOOLS_H
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Creates a code (aka int array) from a number.
 * 
 * @param num Number to convert
 * @param code_length Length of code
 * @param colors Number of colors in the game
 * @return An int array corresponding to the code. Array needs to be freed afterwards
 */
int* code_from_number(long int num, int code_length, int colors);

/**
 * @brief Creates a number from a code, inverse function of code_from_number
 * 
 * @param p_code Code to convert
 * @param code_length Length of code
 * @param colors Number of colors in the game
 * @return A long int corresponding to the code 
 */
long int number_from_code(int* p_code, int code_length, int colors);

/**
 * @brief Plays a guess.
 * 
 * @param p_guess Code guessed
 * @param p_code Right code
 * @param code_length Length of code
 * @param colors Numbers of colors in the game
 * @return An int score
 * 
 * @details Returned score is such that : score%(code_length+1) is the number of pawn of the right color that are misplaced, 
 * and score/(code_length+1) is the number of pawn that are of the right color and correctly placed.
 */
int play_guess(int* p_guess, int* p_code, int code_length, int colors);

#endif