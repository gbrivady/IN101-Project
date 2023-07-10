#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <naive_loader.h>
#include "naive_ppm_writer.h"

int main(void){
    
    printf("*Starting image generator test... ");
    universe glider = naive_load("./data/glider.txt");
    naive_generate_image(glider, 0);
    //tests that the image is what was expected

    FILE *p_fgenerated = NULL;
    FILE *p_fexpected = NULL;

    p_fgenerated = fopen("./out/img-000.ppm", "r");
    p_fexpected = fopen("./data/gliderimage.ppm", "r");

    if(p_fexpected == NULL || p_fgenerated == NULL){
        printf("unable to open images. \n");
        exit(EXIT_FAILURE);
    }
    
    char c_expected;
    char c_generated;
    while(c_expected != EOF && c_generated != EOF){
        c_expected = fgetc(p_fexpected);
        c_generated = fgetc(p_fgenerated);
        assert(c_expected == c_generated);
    }

    printf(" Image created successfully. \n");

    fclose(p_fgenerated);
    fclose(p_fexpected);
    free(glider->grid);
    free(glider);

    return 0;
}