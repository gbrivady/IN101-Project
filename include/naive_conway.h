/**
 * @file naive_conway.h
 * 
 * @brief Implementation of Conway's game of life
 * 
 * @author Grégory Brivady
 * 
 * The universe defined in naive_universe.h will be considered a torus.
 * 
 */
#include <stdbool.h>
#include "naive_universe.h"

#ifndef NAIVE_CONWAY_H
#define NAIVE_CONWAY_H

/** @brief Apply the game's rule once to a universe.
*
* @param u Input universe, will be modified by the function
*/
void naive_step(universe u);

/** @brief Apply the game's rule for the number of steps defined in the universe.
*
* @param u Input universe, will be modified by the function
* @param print The function will print the universe at each step if true.
*/
void naive_simulation(universe u, bool print);

/** @brief Calculate the number of neighbour of one cell.
 * 
 * @param u universe of the cell
 * @param i line of the cell in the grid
 * @param j row of the cell in the grid
 * 
 * @return number of neighbour of the cell in position (i, j) of the universe u
 */
int nbr(universe u, int i, int j);

#endif