/**
 * @file list_conway.h
 * 
 * @brief Implementation of Conway's game of life on list universe
 * 
 * @author Grégory Brivady
 * 
 * This file defines the rules for Conway's game of life.
 * Functions defined here:
 * - a function to apply the game's rule once
 * - a function to apply the game's rule for the number of steps defined in the universe
 * - a function to process the potential newborn cells created in list_step
 * 
 */
#include <stdbool.h>
#include "list_universe.h"

#ifndef LIST_CONWAY_H
#define LIST_CONWAY_H

/** @brief Apply the game's rule once to a universe.
*
* @param lu Input list universe, will be modified by the function
*/
void list_step(list_universe lu);

/** @brief Apply the game's rule for the number of steps defined in the universe.
*
* @param lu Input universe, will be modified by the function
* @param print The function will print the universe at each step if true.
*/
void list_simulation(list_universe lu, bool print);

/** @brief Process the potential newborn cells created in list_step
 * 
 * @param lu universe of the potential newborn cells
 * @param p_list_newborn a pointer to the list of potential newborn cells
 * 
 * @return a pointer to the last cell of the processed list of potential newborn cells
 * 
 * This function does the following:
 * - removes the duplicate cells in the list
 * - process if the newborn cell is dying or not
 * - changes the universe boundaries if necessary
 */
linked_list_cell process_new_cells(list_universe lu, linked_list_cell * p_list_newborn);

#endif