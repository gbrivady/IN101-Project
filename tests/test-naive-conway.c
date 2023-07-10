#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "naive_universe.h"
#include "naive_loader.h"
#include "naive_conway.h"

void test_neighbour(universe u, int i, int j, int result){

    printf(" | calculating number of neighbour of cell (%d, %d)... ", i, j);
    assert(nbr(u, i, j)== result);
    printf("Ok ! \n");
    
}

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
    universe before = naive_load(file_before);
    universe after = naive_load(file_after);
    naive_step(before);
    for(int i = 0; i < before->height; i++){
        for(int j = 0; j < before->width; j++){
            assert(access(before, i, j) == access(after, i, j));
        }
    }
    printf("Ok ! \n");
    free(before->grid);
    free(after->grid);
    free(after);
    free(before);
}

int main(void){

    universe glider = naive_load("./data/glider.txt");
    printf("* Starting neigbhour counting tests on glider universe... \n");
    test_neighbour(glider, 0, 0, 1 );
    test_neighbour(glider, 1, 1, 5 );
    test_neighbour(glider, 2, 19, 1);
    free(glider->grid);
    free(glider);

    printf("*Starting next_step tests on 3x3 universes... \n");
    for(int i = 0; i <= 511; i++){
        test_step(i);
    }

    return 0;
}