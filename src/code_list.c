#include "code_list.h"

//////////////////////// Functions for cells

struct cell *new_cell()
{
    struct cell *p_cell = NULL;
    p_cell = malloc(sizeof(struct cell));
    if (p_cell == NULL)
    {
        printf("Error : cannot allocate memory for new cell");
    }
    p_cell->previous = NULL;
    p_cell->next = NULL;
    p_cell->code = NULL;
    p_cell->tried = false;

    return p_cell;
}

void free_cell(struct cell *p_cell)
{
    if(p_cell->code != NULL){
        free(p_cell->code);
    }
    free(p_cell);
}

//////////////////////// Functions for lists

code_list* new_list()
{
    code_list* p_list = malloc(sizeof(code_list));
    if (p_list == NULL)
    {
        printf("Error : cannot allocate memory for new code list");
    }
    p_list->first = NULL;
    p_list->last = NULL;
    p_list->length = 0;
    return p_list;
}

void append(code_list *p_list, struct cell *p_cell)
{

    if (p_list->length == 0)
    {
        p_list->first = p_cell;
        p_list->last = p_cell;
        p_list->length = 1;
    }
    else
    {
        p_list->last->next = p_cell;
        p_cell->previous = p_list->last;
        p_list->last = p_cell;
        p_list->length = p_list->length + 1;
    }
}

void free_list(code_list *p_list)
{
    struct cell *temp;
    while (p_list->last != NULL)
    {
        temp = p_list->last;
        p_list->last = temp->previous;
        free_cell(temp);
    }
    free(p_list);
}

void remove_cell(code_list* p_list, struct cell *p_cell)
{
    if(p_list->first == p_cell){
        p_list->first = p_cell->next;
    }   
    if(p_list->last == p_cell){
        p_list->last = p_cell->previous;
    }
    if(p_cell->next != NULL){
        p_cell->next->previous = p_cell->previous;
    }
    if(p_cell->previous != NULL){
        p_cell->previous->next = p_cell->next;
    }
    p_list->length -= 1;
}
