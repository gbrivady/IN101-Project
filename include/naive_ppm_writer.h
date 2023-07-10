/**
 * @file naive_ppm_writer.h
 * 
 * @brief Naive PPM image generator for Conway's game of life
 * 
 * @author Grégory Brivady
 * 
 * The image generator loads a universe, and then generate a .ppm image, where:
 * 
 * - each alive cell will be a white pixel represented as 255 255 255
 * - each empty cell will be a black pixel represented as 0 0 0
 */

#include "naive_universe.h"

#ifndef NAIVE_PPM_WRITER_H
#define NAIVE_PPM_WRITER_H
/**
 * @brief take a universe and generate a PPM image in the out directory, named img-num.ppm
 * 
 * @param u the universe that will be used to create the image
 * @param num "num" in the file name
 */

void naive_generate_image(universe u, int num);

#endif