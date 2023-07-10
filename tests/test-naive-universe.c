/**
 * @file test-naive-universe.c
 *
 * @brief Executable to test the naive implementation of the universe
 *
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "naive_universe.h"

void test_access(universe u, int i, int j, char expected_state){
    printf(" | trying to access element in position (%d, %d)... ", i, j);

    assert(i < u->height);
    assert(j < u->width);

    assert(access(u, i, j) == expected_state);

    printf("Ok \n");
}

void test_modify(universe u, int i, int j, char state){
    
    printf(" | trying to modify element in position (%d, %d)... ", i, j);

    assert(i < u->height);
    assert(j < u->width);

    modify(u, i, j, state);

    assert(access(u, i, j) == state);

    printf("Ok \n");
}

int main(void){
    universe u = malloc(sizeof(struct universe));
    if(u == NULL){
        printf("no memory for universe in main from test-naive-universe.c");
    }

    u->height = 5;
    u->width = 4;
    u->n_steps = 1;

    char * grid = malloc((u->height * u->width + 1)*sizeof(char)); //1 extra for \0 at end of string. malloc not necesserary, but did it anyway to test things
    if(grid == NULL){
        printf("no memory for grid in main from test-naive-universe.c");
    }

    char * grid_input = "oooo....o.o..o.oo..o";
    int i = 0;
    while(*(grid_input+i) != '\0'){
        *(grid + i) = *(grid_input+i);
        i += 1;
    }
    *(grid+(u->height * u->width)) = '\0';

    u->grid = grid;

    printf("* Starting tests on naive universe \n"); 
    // /!\  run tests on asymetrical grids to test for intervention between i and j, or height and width
    //      test access before modify, modify uses access
    print_naive_universe(u);

    for(int i = 0; i < u->height; i++){
        for(int j = 0; j < u->width; j++){
            char expected_state = *(u->grid+ i*u->width + j);
            test_access(u, i, j, expected_state);
        }
    }

    for(int i = 0; i < u->height; i++){
        for(int j = 0; j < u->width; j++){
            char current_state = *(u->grid+ i*u->width + j);
            test_modify(u, i, j, (current_state == alive ? empty : alive));
        }
    }

    print_naive_universe(u);

    free(u->grid);
    free(u);

    return 0;
}