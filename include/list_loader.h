/**
 * @file list_loader.h
 * 
 * @brief Load a list universe from a text file. 
 * 
 * @author Grégory Brivady
 * 
 * 
 * The universe loader reads a text file, and returns the universe, as defined in list_universe.h, 
 * that is represented by the text file.
 * 
 * 
 * The text file must be formatted like this :
 * - The first line contains the width and height of the map, separated by a space
 * - The second line is the number of steps
 * - The others lines represents the universe, with the convention :
 *      - 'o' represents an alive cell
 *      - '.' represents an empty cell
 * 
 */

#ifndef LIST_LOADER_H
#define LIST_LOADER_H
#include "list_universe.h"
#include <stdio.h>

/**
 * @brief Loads a list universe from a test file
 * 
 * @param filepath the path to the text file representing the universe
 * 
 * @return the list universe represented by the text file. 
 */
list_universe list_load(char * filepath);

#endif