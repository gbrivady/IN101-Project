#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


#include "list_universe.h"
#include "list_loader.h"
#include "list_conway.h"



void test_step(int n){
    printf(" | testing next_step on %d test universe... ", n);
    char formatted_number[4];
    if(n > 99){
        sprintf(formatted_number, "%d", n);
    }
    else{
        if(n>9){
            sprintf(formatted_number,"0%d", n);
        }
        else{
            sprintf(formatted_number, "00%d", n);
        }
    }

    char file_before[4+16];
    sprintf(file_before, "./data/test-%s.txt", formatted_number);
    char file_after[4+20];
    sprintf(file_after, "./data/test-%s-sol.txt", formatted_number);
    list_universe before = list_load(file_before);
    list_universe after = list_load(file_after);
    list_step(before);
    struct cell_cell * p_current_before = *(before->grid);
    struct cell_cell * p_current_after = *(after->grid);
    //checking cell content
    while(p_current_after != NULL){
        assert(p_current_after->x== p_current_before->x && p_current_after->y== p_current_before->y);
        p_current_before = p_current_before->next;
        p_current_after = p_current_after->next;
    }
    assert(p_current_before == NULL);
    //checking other info
    assert(before->min_x == after->min_x && before->max_x == after->max_x);
    assert(before->min_y == after->min_y && before->max_y == after->max_y);
    printf("Ok ! \n");
    deallocate_list(before->grid);
    deallocate_list(after->grid);
    free(before->grid);
    free(after->grid);
    free(after);
    free(before);
}

int main(void){

    printf("*Starting next_step tests on 3x3 universes... \n");
    for(int i = 0; i <= 511; i++){
        test_step(i);
    }

    return 0;
}