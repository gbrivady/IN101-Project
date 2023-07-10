#include <stdio.h>
#include <stdlib.h>

#include "list_universe.h"

int main(void){

    printf("* Starting test to print list universe... \n");
    list_universe lu = malloc(sizeof(struct list_universe_struct));
    if(lu == NULL){
        printf("no memory for universe in test print list universe");
    }
    lu->min_x = -3;
    lu->max_x = 5;
    lu->min_y = -2;
    lu->max_y = 3;
    lu->n_steps = 1;
    linked_list_cell * p_lu_grid = malloc(sizeof(linked_list_cell));
    if(p_lu_grid == NULL){
        printf("no memory for universe grid in test print list universe");
    }
    *p_lu_grid = NULL;
    append_cell(5, 3, true, p_lu_grid);
    append_cell(5, -2, true, p_lu_grid);
    append_cell(4, 2, true, p_lu_grid);
    append_cell(3, 1, true, p_lu_grid);
    append_cell(2, 0, true, p_lu_grid);
    append_cell(1, -1, true, p_lu_grid);
    append_cell(0, -2, true, p_lu_grid);
    append_cell(-3, -2, true, p_lu_grid);
    lu->grid = p_lu_grid;
    print_list_universe(lu);
    printf(" + Done \n");
    deallocate_list(lu->grid);
    free(p_lu_grid);
    free(lu);

    return 0;
}