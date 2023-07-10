/**
 * A program that creates a universe from a text file,
 * and prints it in the console.
 * 
 * exemple :
 * 
 * ./app-naive-loader ./data/glider.txt 
 * should print an empty universe except for a single glider in the top-left corner.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "naive_universe.h"
#include "naive_loader.h"

int main(int argc, char *argv[]){
    //check that a file  in main arguments
    if (argc != 2) {
        fprintf(stderr, "Error : No file name was provided.\n");
        exit(EXIT_FAILURE);
    }

    //create universe and prints it

    universe u = naive_load(argv[1]);
    print_naive_universe(u);

    //free allocated blocs
    free(u->grid);
    free(u);
    
    return 0;
}

