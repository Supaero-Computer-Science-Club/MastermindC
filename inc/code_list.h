#ifndef CODE_LIST_H
#define CODE_LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct cell
{
    struct cell *previous;
    struct cell *next;
    int *code;
};

/**
 * @brief doubly linked list of codes
 * 
 */
typedef struct code_list
{
    struct cell *first;
    struct cell *last;
    int length;
} code_list;

//////////////////////// Functions for cells

/**
 * @brief Creates an empty cell
 * 
 * @return a pointer to the cell created
 */
struct cell *new_cell();

/**
 * @brief Free a cell from memory
 * 
 * @param p_cell : pointer to the cell to deallocate 
 */
void free_cell(struct cell *p_cell);

//////////////////////// Functions for lists

/**
 * @brief Creates a new empty code list
 * 
 * @return a pointer to the list created
 */
code_list *new_list();

/**
 * @brief Add a cell to the end of the list
 * 
 * @param p_list pointer to the list
 * 
 * @param p_cell pointer to the cell to add
 */
void append(code_list *p_list, struct cell *p_cell);

/**
 * @brief Free a code list from memory, freeing its element in the process
 * 
 * @param p_list pointer to the list to deallocate
 */
void free_list(code_list *p_list);

/**
 * @brief Remove a code from its list, so that code->previous = code->next. 
 *        Don't forget to remove it from memory if necessary
 * 
 * @param p_list : pointer to the list containing the cell
 *
 * @param p_cell : pointer to the cell to remove
 */
void remove_cell(code_list* p_list, struct cell *p_cell);



#endif