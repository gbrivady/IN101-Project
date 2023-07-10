#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "list_universe.h"
#include "list_conway.h"

void list_step(list_universe lu){
    //creates list of newborn cells and decide the future of existing ones
    struct cell_cell * p_current_cell = *(lu->grid);
    linked_list_cell * p_list_newborn = malloc(sizeof(linked_list_cell));
    if(p_list_newborn == NULL){
        printf("no memory for newborn list in list_step");
    }
    *p_list_newborn = NULL;
    int neighbor_count = 0;
    int cell_x;
    int cell_y;
    while(p_current_cell != NULL){
        neighbor_count = 0;
        cell_x = p_current_cell->x;
        cell_y = p_current_cell->y;
        //we split the search of neighbors in two : we look for neighbors before the cell 
        //by using lu->grid in find_cell_sorted (search from the start) and we look for neighbors after the cell
        //by using &p_current_cell (search from current cell)

        //cells before
        for(int j = -1; j <= 1; j++){
            if (find_cell_sorted(cell_x-1 ,cell_y+j , lu->grid) != NULL){
                neighbor_count ++;
            }else{
                append_cell(cell_x-1 ,cell_y+j, true, p_list_newborn);
            }
        }
        if (find_cell_sorted(cell_x ,cell_y-1 , lu->grid) != NULL){
                neighbor_count ++;
            }else{
                append_cell(cell_x ,cell_y-1, true, p_list_newborn);
            }


       //cells after
       if (find_cell_sorted(cell_x ,cell_y+1 , &p_current_cell) != NULL){
                neighbor_count ++;
            }else{
                append_cell(cell_x ,cell_y+1, true, p_list_newborn);
            }

        for(int j = -1; j <= 1; j++){
            if (find_cell_sorted(cell_x+1 ,cell_y+j , &p_current_cell) != NULL){
                neighbor_count ++;
            }else{
                append_cell(cell_x+1 ,cell_y+j, true, p_list_newborn);
            }
        }
        if(neighbor_count == 2 || neighbor_count == 3){
            p_current_cell->dying = false;
        }else{
            p_current_cell->dying = true;
        }
        p_current_cell = p_current_cell->next;
        
    }
    if(*p_list_newborn == NULL || (*p_list_newborn)->next==NULL){
        remove_dying(lu->grid);
        lu->n_steps --;
        free(p_list_newborn);
        return;
    }
    //process the newborn cells
    struct cell_cell * p_last_newborn = process_new_cells(lu, p_list_newborn);
    //concatenates both list & sorts them
    p_last_newborn->next = *(lu->grid);
    free(lu->grid);
    lu->grid = p_list_newborn;
    merge_sort(lu->grid);
    //kill the dying cells
    remove_dying(lu->grid);
    lu->n_steps --;

}

linked_list_cell process_new_cells(list_universe lu, linked_list_cell * p_list_newborn){

    merge_sort(p_list_newborn);
    struct cell_cell * p_current_cell = *p_list_newborn;
    struct cell_cell * p_next_cell = p_current_cell->next;
    int dup_counter = 0;
    while(p_next_cell != NULL){
        if(p_next_cell->x == p_current_cell->x && p_next_cell->y == p_current_cell->y){
            dup_counter++;
            p_current_cell->next = p_next_cell->next;
            free(p_next_cell);
            p_next_cell = p_current_cell->next;
        }else{
            if(dup_counter == 2){
                p_current_cell->dying = false; //true by default
                //rescale the universe if required
                if(p_current_cell->x < lu->min_x){
                    lu->min_x = p_current_cell->x;
                }
                if(p_current_cell->x > lu->max_x){
                    lu->max_x = p_current_cell->x;
                }
                if(p_current_cell->y < lu->min_y){
                    lu->min_y = p_current_cell->y;
                }
                if(p_current_cell->y > lu->max_y){
                    lu->max_y = p_current_cell->y;
                }
               
            }
            p_current_cell = p_next_cell;
            p_next_cell = p_current_cell->next;
            dup_counter = 0;
        }
    }

    return p_current_cell;

}

void list_simulation(list_universe lu, bool print){
    //print initial state
    if(print){
        print_list_universe(lu);
        printf("\n");
    }
    while(lu->n_steps > 0){
        list_step(lu);
        if(print){
            print_list_universe(lu);
            printf("\n");
        }
    }
}
