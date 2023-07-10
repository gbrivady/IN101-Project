#include <stdio.h>
#include <stdlib.h>

#include "list_universe.h"
#include "list_ppm_writer.h"

void list_generate_image(list_universe lu, int num){

    //format num into a 3-digit number
    char formatted_number[4];
    sprintf(formatted_number, "%03d", num);

    //create file
    char filepath[18];
    sprintf(filepath, "./out/img-%s.ppm", formatted_number);

    FILE * p_output = NULL;
    p_output = fopen(filepath, "w");
    if (p_output == NULL) {
        fprintf(stderr, "can't create image at %s", filepath);
        exit(EXIT_FAILURE);
    }

    //create image
    struct cell_cell * p_next_alive = *(lu->grid);
    int min_x = lu->min_x;
    int max_x = lu->max_x;
    int min_y = lu->min_y;
    int max_y = lu->max_y;
    fprintf(p_output, "P3\n");
    fprintf(p_output, "%d %d\n",max_y-min_y+1, max_x-min_x+1);
    fprintf(p_output, "255\n");
    for(int i = min_x; i <= max_x; i++){
        for(int j = min_y; j <= max_y; j++){
            if(p_next_alive != NULL){
                if(i == p_next_alive->x && j == p_next_alive->y){
                    fprintf(p_output, "255 255 255 ");
                    p_next_alive = p_next_alive->next;
                }else{
                    fprintf(p_output, "0 0 0 ");
                }
            }else{
                fprintf(p_output, "0 0 0 ");
            }
        
        }
        fprintf(p_output, "\n");
    }
    fclose(p_output);
}
