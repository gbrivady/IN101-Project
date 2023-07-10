#include <stdio.h>
#include <stdlib.h>
#include "naive_loader.h"


universe naive_load(char * filepath){

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
    universe u = malloc(sizeof(struct universe));
    if(u == NULL){
        printf("no memory for universe in naive_load");
    }
    char * grid = malloc((height * width + 1)*sizeof(char));
    if(grid == NULL){
        printf("no memory for grid in naive_load");
    }

    u->height = height;
    u->width = width;
    u->n_steps = n_steps;
    u->grid = grid;

    //fill the grid
    char temp = ' ';

    for(int i = 0; i < height; i++){

        for(int j = 0; j < width; j++){
            fscanf(p_file, "%c", &temp);
            modify(u, i, j, temp);
        }
        fscanf(p_file, "%c\n", &temp);
    }
    *(u->grid+width*height) = '\0';
    
    fclose(p_file);

    return u;
}