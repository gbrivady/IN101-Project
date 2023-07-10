/**
 * @file linked_list_cell.h
 * 
 * @brief Implementation of linked list of cells for Conway's Game of Life
 * 
 * @author Grégory Brivady
 * 
 * This is a simple implementation of linked lists of cells for Game of Life.
 * Each element of the list will contain :
 *  - the coordinate of the cell it represents
 *  - a boolean flag indicating if the cell will die at the next state of computation
 * 
 * Functions defined here :
 *  - a function that append an element at the beginning of a list
 *  - a function that find a cell given its coordinates
 *  - a function that remove the dying cells from the list
 *  - a function that sorts the list using merge sort
 *  - a function to deallocate a list
 *  - a function that tests if a cell is strictly smaller than another, using lexicographic order
 */ 

#ifndef LINKED_LIST_CELL_H
#define LINKED_LIST_CELL_H

#include <stdbool.h>

/**
 * @brief Alias for the linked list of cells
 */
typedef struct cell_cell * linked_list_cell;

/**
 * @brief The structure representing the linked list
 */
struct cell_cell {
    int x;
    int y;
    bool dying;
    struct cell_cell * next;
};

/**
 * @brief Append an element at the head of the list
 * 
 * @param cell_x first coordinate of the cell
 * @param cell_y second coordinate of the cell
 * @param state the boolean flag indicating if the cell will die at the next state of computation
 * @param p_list a pointer to the list in which the element will be added
 */
void append_cell(int cell_x, int cell_y, bool state, linked_list_cell * p_list);

/**
 * @brief Finds a cell given its coordinates
 * 
 * @param cell_x first coordinate
 * @param cell_y second coordinate
 * @param p_list a pointer to the list in which to search
 * 
 * @return a pointer to the cell whose coordinate are cell_x and cell_y, 
 *         and a NULL pointer if the cell could not be found.
 */
linked_list_cell find_cell(int cell_x, int cell_y, linked_list_cell * p_list);

/**
 * @brief Removes the dying cells from a list
 * 
 * @param p_list a pointer to the list that needs removing
 */
void remove_dying(linked_list_cell * p_list);


/**
 * @brief A simple merge sort on list.
 * 
 * @param p_list a pointer to the list to sort
 * 
 * The sort is by lexicographic order, ie (a, b) < (a', b') if and and only if:
 * a < a' or (a = a' AND b < b')
 * 
 */
void merge_sort(linked_list_cell * p_list);

/**
 * @brief Strict lexicographic order on cells.
 * 
 * @param p_cell1 a pointer to the first cell whose coordinates are (a, b)
 * @param p_cell2 a pointer to the second cell whose coordinates are (a', b')
 * 
 * @return a boolean flag : true if a < a' OR (a == a' AND b < b' ); false otherwhise.
 *         NULL cell is considered the greatest cell possible.
 *         
 * 
 */

bool less_than_cell(struct cell_cell * p_cell1, struct cell_cell * p_cell2);

/**
 * @brief Deallocate a list
 * 
 * @param list a pointer to the list to be deallocated
 */
void deallocate_list(linked_list_cell * p_list);


#endif


