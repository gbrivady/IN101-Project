#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "linked_list_cell.h"



void test_append(void){

    printf(" | testing append on empty list... ");
    linked_list_cell test_append_1;
    linked_list_cell * p_test_append_1 = &test_append_1;
    *p_test_append_1 = NULL;
    append_cell(1,2, true, p_test_append_1);
    test_append_1 = *p_test_append_1;

    assert(test_append_1->x == 1 && test_append_1->y == 2 && test_append_1->dying && test_append_1->next == NULL);

    printf("Ok ! \n");

    printf(" | testing append on non-empty list... ");
    append_cell(2,3, true, p_test_append_1);

    assert((*p_test_append_1)->next->x == 1 &&(*p_test_append_1)->next->y == 2 && \
    (*p_test_append_1)->next->dying && (*p_test_append_1)->next->next == NULL);

    assert((*p_test_append_1)->x == 2 && (*p_test_append_1)->y == 3 && (*p_test_append_1)->dying);

    printf("Ok ! \n");
    free((*p_test_append_1)->next);
    free(*p_test_append_1);
}

void test_find(){
    linked_list_cell * p_test_find = malloc(sizeof(linked_list_cell));
    *p_test_find = NULL;
    append_cell(1, 2, false, p_test_find);
    append_cell(2, 5, true, p_test_find);
    printf(" | testing impossible find... ");
    linked_list_cell found = find_cell(0, 0, p_test_find);
    assert(found == NULL); 
    printf("Ok ! \n");

    printf(" | testing possible find... ");
    found = find_cell(1, 2, p_test_find);
    assert(found->x == 1 && found->y == 2 && !found->dying );
    printf("Ok ! \n");
    free((*p_test_find)->next);
    free(*p_test_find);
    free(p_test_find);
}

void test_remove_dying(){
    linked_list_cell * p_test_find = malloc(sizeof(linked_list_cell));
    if(p_test_find == NULL){printf("error in malloc of remove dying test \n");}
    *p_test_find = NULL;
    append_cell(1, 2, true, p_test_find);
    append_cell(2, 5, true, p_test_find);
    printf(" | testing remove dying on full dying list... ");
    remove_dying(p_test_find);
    assert(*p_test_find == NULL); 
    printf("Ok ! \n");
    printf(" | testing remove dying on mixed list... ");
    append_cell(1, 2, true, p_test_find);
    append_cell(2, 5, false, p_test_find);
    append_cell(10, 2, true, p_test_find);
    remove_dying(p_test_find);
    assert((*p_test_find)->x == 2 && (*p_test_find)->y == 5 && (*p_test_find)->next == NULL);
    printf("Ok ! \n");
    deallocate_list(p_test_find);
    free(p_test_find);
}

void test_merge_sort(){
    printf(" | testing merge_sort on sorted list...");
    linked_list_cell * p_test_sort = malloc(sizeof(linked_list_cell));
    if(p_test_sort == NULL){printf("error in malloc of merge sort test \n");}
    *p_test_sort = NULL;
    append_cell(6,1,true, p_test_sort);
    append_cell(1,3,true, p_test_sort);
    append_cell(1,1,true, p_test_sort);
    merge_sort(p_test_sort);
    assert((*p_test_sort)->x == 1 && (*p_test_sort)->y == 1);
    assert((*p_test_sort)->next->x == 1 && (*p_test_sort)->next->y == 3);
    assert((*p_test_sort)->next->next->x == 6 && (*p_test_sort)->next->next->y == 1);
    remove_dying(p_test_sort);
    printf("Ok ! \n");

    printf(" | testing merge_sort on reversed list...");
    append_cell(1,1,true, p_test_sort);
    append_cell(1,3,true, p_test_sort);
    append_cell(6,1,true, p_test_sort);
    merge_sort(p_test_sort);
    assert((*p_test_sort)->x == 1 && (*p_test_sort)->y == 1);
    assert((*p_test_sort)->next->x == 1 && (*p_test_sort)->next->y == 3);
    assert((*p_test_sort)->next->next->x == 6 && (*p_test_sort)->next->next->y == 1);
    printf("Ok ! \n");
    deallocate_list(p_test_sort);
    free(p_test_sort);
}

int main(void){

    printf("* Starting linked_list_cell test... \n");
    test_append();
    test_find();
    test_remove_dying();
    test_merge_sort();
    printf(" + Done \n");
    return 0;
}