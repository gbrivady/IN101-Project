#include <stdio.h>
#include <stdlib.h>

#include "naive_universe.h"
#include "naive_ppm_writer.h"

void naive_generate_image(universe u, int num){

    //format num into a 3-digit number
    char formatted_number[4];
    if(num > 99){
        sprintf(formatted_number, "%d", num);
    }
    else{
        if(num>9){
            sprintf(formatted_number,"0%d", num);
        }
        else{
            sprintf(formatted_number, "00%d", num);
        }
    }

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
    int width = u->width;
    int height = u->height;
    fprintf(p_output, "P3\n");
    fprintf(p_output, "%d %d\n", width, height);
    fprintf(p_output, "255\n");
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
        {
            if(access(u, i, j) == alive){
                fprintf(p_output, "255 255 255 ");
            }else{
                fprintf(p_output, "0 0 0 ");
            }
        }
        fprintf(p_output, "\n");
        
    }

    fclose(p_output);
    

};