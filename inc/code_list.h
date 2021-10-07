#ifndef CODE_LIST_H
#define CODE_LIST_H
#include <stdbool.h>
#include "tools.h"

typedef struct cell
{
    struct cell* previous;
    struct cell* next;
    int* code;
    bool* tried;
};

/**
 * @brief doubly linked list of codes
 * 
 */
typedef struct code_list
{
    struct cell* first;
    struct cell* last;
    int length;
}code_list;

//////////////////////// Functions for cells

/**
 * @brief Creates an empty cell
 * 
 * @return a pointer to the cell created
 */
struct cell* new_cell();

/**
 * @brief Remove a code from the list, so that code->previous = code->next. 
 *        Don't forget to remove it from memory if necessary
 * 
 * @param cell : cell to remove
 */
void remove_cell(struct cell* cell);

/**
 * @brief Free a cell from memory
 * 
 * @param cell : cell to deallocate 
 */
void free_cell(struct cell* cell);

//////////////////////// Functions for lists

/**
 * @brief Creates a new empty code list
 * 
 * @return a pointer to the list created
 */
code_list* new_list();

/**
 * @brief Add a cell to the end of the list
 * 
 * @param list 
 */
void append(code_list* list, struct cell* cell);

/**
 * @brief Free a code list from memory
 * 
 * @param list 
 */
void free_list(code_list* list);

#endif