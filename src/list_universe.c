#include <stdlib.h>
#include <stdio.h>

#include "list_universe.h"

linked_list_cell find_cell_sorted(int cell_x, int cell_y, linked_list_cell * p_list){
    //if the list is sorted, we can stop looking for the cell if we get to a cell that is greater than the one we are looking for.
    struct cell_cell * p_cell = *p_list;
    while (p_cell != NULL)
    {   
        if(p_cell->x < cell_x){
            p_cell = p_cell->next;
        }
        else{
            if(p_cell->x == cell_x){
                if(p_cell->y < cell_y){
                    p_cell = p_cell->next;
                }else{
                    if(p_cell->y == cell_y){
                        return p_cell;
                    }else{
                        return NULL;
                    }
                }
            }else{
                return NULL;
            }
        }
    }
    return NULL;
}

void print_list_universe(list_universe lu){
    struct cell_cell * p_next_alive = *(lu->grid);
    int min_x = lu->min_x;
    int max_x = lu->max_x;
    int min_y = lu->min_y;
    int max_y = lu->max_y;

    for(int i = min_x; i <= max_x; i++){
        for(int j = min_y; j <= max_y; j++){
            if(p_next_alive != NULL){
                if(i == p_next_alive->x && j == p_next_alive->y){
                    printf("o");
                    p_next_alive = p_next_alive->next;
                }else{
                    printf(".");
                }
            }else{
                printf(".");
            }
            

        }
        printf("\n");
    }
}
