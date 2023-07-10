#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list_universe.h"


int main(void){

    printf("* Starting test of find function for sorted linked lists... \n");

    linked_list_cell * p_test_find = malloc(sizeof(linked_list_cell));
    if(p_test_find == NULL){
        printf("no memory for list in test find sorted \n");
    }
    *p_test_find = NULL;
    append_cell(2, 2, false, p_test_find);
    append_cell(1, 5, true, p_test_find);
    printf(" | testing impossible find... ");
    linked_list_cell found = find_cell_sorted(0, 0, p_test_find);
    assert(found == NULL); 
    printf("Ok ! \n");

    printf(" | testing possible find... ");
    found = find_cell_sorted(1, 5, p_test_find);
    assert(found->x == 1 && found->y == 5 && found->dying );
    printf("Ok ! \n");
    deallocate_list(p_test_find);
    free(p_test_find);

    printf(" + Done \n");

    return 0;
}