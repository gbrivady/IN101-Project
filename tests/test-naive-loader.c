/**
 * @file test-naive-universe.c
 *
 * @brief Executable to test the loading of a naive universe from a text file
 *
 * @author Grégory Brivady
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "naive_loader.h"

void test_loading(universe u){

    printf(" | testing universe... ");

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

    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 20; j++){
            fscanf(p_file, "%c", &temp);
            assert(temp == access(u, i, j));
        }
        fscanf(p_file, "%c\n", &temp);
    }

    printf("Ok !\n");

    fclose(p_file);

}

int main(void){

    universe u = naive_load("./data/glider.txt");

    printf("*Starting naive loader test with glider... \n");

    printf(" | testing height... ");
    assert(u->height == 21);
    printf("Ok! \n");

    printf(" | testing width... ");
    assert(u->width == 20);
    printf("Ok! \n");

    printf(" | testing number of simulation steps... ");
    assert(u->n_steps == 10);
    printf("Ok! \n");

    test_loading(u);

    free(u->grid);
    free(u);
}