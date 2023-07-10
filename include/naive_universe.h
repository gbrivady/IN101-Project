/**
 * @file naive_universe.h
 * 
 * @brief Definition of the naive implementation of the universe for Conway's game of life
 * 
 * @author Grégory Brivady
 * 
 * This is the definition of the naive implementation of the universe for Conway's game of life.
 * The universe is represented by a pointer to a structure containing : 
 * - the height of the universe
 * - the width of the universe
 * - the number of steps to execute
 * - a pointer to char representing the universe elements
 * 
 * 
 * Functions defined here :
 * - a function to print the universe
 * - a function access the grid element at row i and column j
 * - a function to modify the grid element at row i and column j
 * 
*/

#ifndef NAIVE_H
#define NAIVE_H

/* macros to ease the reading and writing of code */
#define alive 'o'
#define empty '.'

/**
 * @brief An alias for the structure representing the universe
 */
typedef struct universe * universe;

/**
 * @brief The structure representing the universe
 */
struct universe {
    int height;
    int width;
    int n_steps;
    char* grid;
};

/**
 * @brief Access a grid element
 * 
 * @param u the universe where is the element
 * @param i row of the element
 * @param j column of the element
 * 
 * @return a char : 'o' if the cell is alive, '.' if the cell is empty
 */
char access(universe u, int i, int j);

/**
 * @brief Modify a grid element
 * 
 * @param u the universe from which the element is to be modified
 * @param i row of the element
 * @param j column of the element
 * @param state new state of the element
 */
 void modify(universe u, int i, int j, char state);

/**
 * @brief Print a universe
 * 
 * @param u the universe to be printed
 */
void print_naive_universe(universe u);


#endif