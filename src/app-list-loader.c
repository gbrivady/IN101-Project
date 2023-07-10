/**
 * A program that creates a list universe from a text file,
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
#include "list_universe.h"
#include "list_loader.h"

int main(int argc, char *argv[]){
    //check that a file  in main arguments
    if (argc != 2) {
        fprintf(stderr, "Error : No file name was provided.\n");
        exit(EXIT_FAILURE);
    }

    //create universe and prints it

    list_universe lu = list_load(argv[1]);
    print_list_universe(lu);

    //free allocated blocs
    deallocate_list(lu->grid);
    free(lu->grid);
    free(lu);
    
    return 0;
}