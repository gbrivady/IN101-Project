#include <stdio.h>
#include <stdlib.h>
#include "list_universe.h"
#include "list_loader.h"


list_universe list_load(char * filepath){

    //first get constants from text file
    int height = 0;
    int width = 0;
    int n_steps = 0;

    FILE *p_file = NULL;

    p_file = fopen(filepath, "r");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s", filepath);
        exit(EXIT_FAILURE);
    }
    fscanf(p_file, "%d %d", &width, &height);
    fscanf(p_file, "%d\n", &n_steps); //p_file now points to the start of the third line


    //allocate space for universe and its grid
    list_universe lu = malloc(sizeof(struct list_universe_struct));
    if(lu == NULL){
        printf("no memory for universe in list_load");
    }
    linked_list_cell * p_lu_grid = malloc(sizeof(linked_list_cell));
    if(p_lu_grid == NULL){
        printf("no memory for universe grid in list_load");
    }
    *p_lu_grid = NULL;

    lu->min_x = 0;
    lu->max_x = height-1;
    lu->min_y = 0;
    lu->max_y = width-1;
    lu->n_steps = n_steps;

    //fill the grid
    char temp = ' ';

    for(int i = 0; i < height; i++){

        for(int j = 0; j < width; j++){
            fscanf(p_file, "%c", &temp);
            if(temp == 'o'){
                append_cell(i, j, true, p_lu_grid);
            }
        }
        fscanf(p_file, "%c\n", &temp);
    }
    //flip the list

    merge_sort(p_lu_grid);
    

    lu->grid=p_lu_grid;

    fclose(p_file);

    return lu;
}