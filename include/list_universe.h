/**
 * @file list_universe.h
 * 
 * @brief Definition of the universe using linked list of cells
 * 
 * @author Grégory Brivady
 * 
 * This is the definition of the universe using linked list of cells, as defined in linked_list_cell.
 * The universe will be represented by a pointer to a structure containing:
 * - an int corresponding to the min bound along the ordinate
 * - an int corresponding to the max bound along the ordinate
 * - an int corresponding to the min bound along the abscissa
 * - an int corresponding to the max bound along the abscissa
 * - the number of steps to execute
 * - a pointer to a linked list of cells representing its elements, sorted by lexicographic order
 * 
 * Functions defined here:
 * - a function to print the universe
 * - a function that find a cell given its coordinates, knowing the list of cells is sorted
 */
#ifndef LIST_UNIVERSE_H
#define LIST_UNIVERSE_H

#include "linked_list_cell.h"

/** 
 * @brief an alias for the structure representing the universe
 */
typedef struct list_universe_struct * list_universe;

/**
 * @brief The structure representing the universe
 */
struct list_universe_struct {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
    int n_steps;
    linked_list_cell * grid;

};

/**
 * @brief the find_cell function for linked lists, optimized for sorted ones
 * 
 * @param cell_x first coordinate
 * @param cell_y second coordinate
 * @param p_list a pointer to the list in which to search
 * 
 * @return a pointer to the cell whose coordinate are cell_x and cell_y, 
 *         and a NULL pointer if the cell could not be found.
 */

linked_list_cell find_cell_sorted(int cell_x, int cell_y, linked_list_cell * p_list);

/** 
 * @brief A function to print a universe implemented with a linked list
 */

void print_list_universe(list_universe lu);

#endif