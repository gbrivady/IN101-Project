#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "naive_universe.h"
#include "naive_conway.h"


int nbr(universe u, int i, int j){
    int n = - (access(u, i, j) == alive);
    //if the cell is alive, it will count as its own neighbour in the loop below, so we initialize
    //n at -1 in this case.


    int width = u->width;
    int height = u->height;

    for(int i2 = -1; i2 < 2; i2++){
        for(int j2 = -1; j2 < 2; j2++){
            //modulos have to be positive, so we use (i % n + n) % n instead of i % n
            n += (access(u, ((i+i2) % height + height) % height, ((j+j2) % width + width) % width)== alive);
        }
    }
    return n;
}

//functions from signature

void naive_step(universe u){
    u->n_steps--;
    int height = u->height;
    int width = u->width;

    //temporary grid to store new value of cells
    char * temp_grid = malloc((height * width + 1)*sizeof(char));
    if(temp_grid == NULL){
        printf("no memory for temp_grid in naive_step");
    }

    char new_state;
    int nb_nbr;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            //number of neighbours
            nb_nbr = nbr(u, i, j);

            //apply the rules
            if(access(u, i, j) == alive){
                if(nb_nbr == 2 || nb_nbr == 3){
                    new_state = alive;
                }
                else{
                    new_state = empty;
                }
            }
            else{
                if(nb_nbr == 3){
                    new_state = alive;
                }
                else{
                    new_state = empty;
                }
            }
            //put the new state in temporary grid
            *(temp_grid+ i* width + j) = new_state;
        }
    }
    *(temp_grid + width*height) = '\0';
    //replaces old grid for new one.
    free(u->grid);
    u->grid = temp_grid;
}

void naive_simulation(universe u, bool print){
    
    if(print){
            print_naive_universe(u);
        }
    while (u->n_steps > 0){
        naive_step(u);
        if(print){
            print_naive_universe(u);
        }
    }
    
}