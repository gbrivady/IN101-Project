/**
 * @file test-list-loader.c
 *
 * @brief Executable to test the loading of a list universe from a text file
 *
 * @author Grégory Brivady
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_universe.h"
#include "list_loader.h"

void test_loading(list_universe lu){

    printf(" | testing list universe ... ");

    FILE *p_file = NULL;

    p_file = fopen("./data/glider.txt", "r");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file ./data/glider.txt !");
        exit(EXIT_FAILURE);
    }
    int width = 0;
    int height = 0;
    int n_steps = 0;
    int fscanf_result = 0;
    fscanf_result = fscanf(p_file, "%d %d", &width, &height);
    assert(fscanf_result == 2);
    fscanf_result = fscanf(p_file, "%d\n", &n_steps);
    assert(fscanf_result == 1);
    char temp = ' ';
    struct cell_cell * p_found;
    p_found = NULL;
    
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 20; j++){
            fscanf(p_file, "%c", &temp);
            if(temp == 'o'){
                p_found = find_cell_sorted(i, j, lu->grid);
                assert(p_found != NULL);
            }
        }
        fscanf(p_file, "%c\n", &temp);
    }

    printf("Ok !\n");

    fclose(p_file);

}

int main(void){

    list_universe lu = list_load("./data/glider.txt");

    printf("*Starting list loader test with glider... \n");

    printf(" | testing height... ");
    assert(lu->max_x == 20);
    printf("Ok! \n");

    printf(" | testing width... ");
    assert(lu->max_y == 19);
    printf("Ok! \n");

    printf(" | testing number of simulation steps... ");
    assert(lu->n_steps == 10);
    printf("Ok! \n");

    test_loading(lu);

    deallocate_list(lu->grid);
    free(lu->grid);
    free(lu);
}