#include <stdio.h>

#include "naive_universe.h"

char access(universe u, int i, int j){
    char *grid = u->grid;
    return *(grid + i * u->width + j);
}

void modify(universe u, int i, int j, char state){
    
    *((u->grid)+i* u->width + j) = state;
}

void print_naive_universe(universe u){

    for(int i = 0; i < u->height; i++){
        for(int j = 0; j < u->width; j++){
            printf("%c", *(u->grid+ i*u->width + j));
        }
        printf("\n");
    }

}

