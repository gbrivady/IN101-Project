/**
 * A program that creates a universe from a text file, run the simulation,
 * and generate images at each step of the simulation.
 * 
 * exemple :
 * 
 * ./app-naive-conway ./data/glider.txt 
 * should strat as an empty universe except for a single glider in the top-left corner,
 * and do 10 steps of simulation.
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "naive_universe.h"
#include "naive_loader.h"
#include "naive_conway.h"
#include "naive_ppm_writer.h"

int main(int argc, char *argv[]){
    //check that there is a file in main arguments
    if (argc != 2) {
        fprintf(stderr, "Error : No file name was provided.\n");
        exit(EXIT_FAILURE);
    }
    universe u = naive_load(argv[1]);
    int num = 0;
    naive_generate_image(u, num);

    while (u->n_steps > 0){
        naive_step(u);
        num++;
        naive_generate_image(u, num);
        
        
    }
    free(u->grid);
    free(u);
    return 0;
}