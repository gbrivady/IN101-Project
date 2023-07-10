/**
 * A program that creates a list universe from a text file, run the simulation,
 * and prints each step of the simulation.
 * 
 * exemple :
 * 
 * ./app-list-conway ./data/glider.txt 
 * should start as an empty universe except for a single glider in the top-left corner,
 * and do 10 steps of simulation.
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "list_universe.h"
#include "list_loader.h"
#include "list_conway.h"
#include "list_ppm_writer.h"

int main(int argc, char *argv[]){
    //check that there is a file in main arguments
    if (argc != 2) {
        fprintf(stderr, "Error : No file name was provided.\n");
        exit(EXIT_FAILURE);
    }
    list_universe lu = list_load(argv[1]);
    int num = 0;
    list_generate_image(lu, num);

    while (lu->n_steps > 0){
        list_step(lu);
        num++;
        list_generate_image(lu, num);
    }
    deallocate_list(lu->grid);
    free(lu->grid);
    free(lu);
    return 0;
}