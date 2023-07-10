#include <stdlib.h>
#include <stdio.h>
#include "linked_list_cell.h"


void append_cell(int cell_x, int cell_y, bool state, linked_list_cell * p_list){

    struct cell_cell * p_new_cell = malloc(sizeof(struct cell_cell));
    if(p_new_cell == NULL){
        printf("No memory for new_cell in append_cell ! \n");
    }
    p_new_cell->x = cell_x;
    p_new_cell->y = cell_y;
    p_new_cell->dying = state;
    p_new_cell->next = *p_list;
    *p_list = p_new_cell;
}

linked_list_cell find_cell(int cell_x, int cell_y, linked_list_cell * p_list){

    struct cell_cell * p_cell = *p_list;
    while (p_cell != NULL)
    {
        if(p_cell->x == cell_x && p_cell->y == cell_y){
            return p_cell;
        }
        //else we keep going
        p_cell = p_cell->next;
    }
    return NULL;
}

void remove_dying(linked_list_cell * p_list){
    if(*p_list != NULL){
        struct cell_cell * p_current_cell = *p_list;

        //if first cell is dying:
        if(p_current_cell->dying){
            *p_list = p_current_cell->next;
            free(p_current_cell);
            remove_dying(p_list);
        }
        else{
            struct cell_cell * p_next_cell = p_current_cell->next;
            while (p_next_cell != NULL){
                if(p_next_cell->dying){
                    p_next_cell = p_next_cell->next;
                    free(p_current_cell->next);
                    p_current_cell->next = p_next_cell;
                }
                else{
                    p_current_cell = p_next_cell;
                    p_next_cell = p_next_cell->next;
                }
            }
            
        }
    }
}
bool less_than_cell(struct cell_cell * p_cell1, struct cell_cell * p_cell2){
    if(p_cell1 == NULL){
        return false;
    }
    if(p_cell2 == NULL){
        return true;
    }
    int x1 = p_cell1->x;
    int x2 = p_cell2->x;
    int y1 = p_cell1->y;
    int y2 = p_cell2->y;
    
    return (x1 < x2 || (x1 == x2 && y1 < y2));
}

void merge_sort(linked_list_cell * p_list){
    if(p_list != NULL){
        if(*p_list == NULL){
            return;
        }
        if((*p_list)->next == NULL){
            return;
        }
        //search for middle of the list to split it
        struct cell_cell * p_middle = *p_list; //Will be the pointer to the middle of the list
        struct cell_cell * p_end = (*p_list)->next; //Will go to the end of the list
        while(p_end != NULL){
            p_end = p_end->next;
            if(p_end != NULL){
                p_middle = p_middle->next;
                p_end = p_end->next;
            }
        }
        //Now we split the list:
        linked_list_cell * p_list2 = malloc(sizeof(linked_list_cell));
        if(p_list2 == NULL){
            printf("No memory for split in merge_sort \n");
        }
        *p_list2 = p_middle->next;
        p_middle->next = NULL;
        //And we sort both list:
        merge_sort(p_list);
        merge_sort(p_list2);

        //Now we merge the lists:
        struct cell_cell * p_cell1 = *p_list;
        struct cell_cell * p_cell2 = *p_list2;
        linked_list_cell result_list = NULL;

        //init the first cell of result list
        if(less_than_cell(p_cell1,p_cell2)){
            result_list = p_cell1;
            p_cell1 = p_cell1->next;
        }else{
            result_list = p_cell2;
            p_cell2 = p_cell2->next;
        }
        struct cell_cell * p_cellr = result_list;

        while(p_cell1!= NULL || p_cell2 != NULL){
            if(less_than_cell(p_cell1,p_cell2)){
                p_cellr->next = p_cell1;
                p_cellr = p_cell1;
                p_cell1 = p_cell1->next;
            }
            else{
                p_cellr->next = p_cell2;
                p_cellr = p_cell2;
                p_cell2 = p_cell2->next;
            }
        }
        *p_list = result_list;
        free(p_list2);

    }
}

void deallocate_list(linked_list_cell * p_list){
    struct cell_cell * p_current_cell = *p_list;
    struct cell_cell * p_temp_cell = NULL;

    while(p_current_cell != NULL){

        p_temp_cell = p_current_cell;
        p_current_cell = p_current_cell->next;
        free(p_temp_cell);

    }
}
