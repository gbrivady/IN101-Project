/**
 * @file list_ppm_writer.h
 * 
 * @brief List PPM image generator for Conway's game of life
 * 
 * @author Grégory Brivady
 * 
 * The image generator loads a universe, and then generate a .ppm image, where:
 * 
 * - each alive cell will be a white pixel represented as 255 255 255
 * - each empty cell will be a black pixel represented as 0 0 0
 */

#include "list_universe.h"

#ifndef LIST_PPM_WRITER_H
#define LIST_PPM_WRITER_H
/**
 * @brief take a list universe and generate a PPM image in the out directory, named img-num.ppm
 * 
 * @param lu the list universe that will be used to create the image
 * @param num "num" in the file name
 */

void list_generate_image(list_universe lu, int num);

#endif