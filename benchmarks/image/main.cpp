/**
 * @file main.cpp
 * @brief Image class benchmark.
 */

#include "camera/image.hpp"
#include <chrono>
#include <iostream>
#include <cstdlib>

#define NB_OF_IMAGES    100
#define IMAGE_WIDTH     3400
#define IMAGE_HEIGHT    1300

int main(int argc, char **argv) {

    Image *i[NB_OF_IMAGES];
    for(unsigned int incr = 0; incr < NB_OF_IMAGES; incr++) {
        i[incr] = new Image(IMAGE_WIDTH, IMAGE_HEIGHT);
        
        char *buffer = i[incr]->getImageBuffer(); 
        for (unsigned int r = 0; r < IMAGE_HEIGHT; r++) {        
            for (unsigned int c = 0; c < IMAGE_WIDTH; c++) {
                buffer[(r * IMAGE_WIDTH) + c] = (char) (rand() & 0xFF);
            }
        }
    }

    #ifndef PROFILING
    const auto startTime = std::chrono::monotonic_clock::now(); 
    #endif

    for(unsigned int incr = 0; incr < NB_OF_IMAGES; incr++) {
        i[incr]->writeToPGM("image.pgm"); 
    }

    #ifndef PROFILING
    double elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::monotonic_clock::now() - startTime).count() / 1000.0;

    std::cout << "Average time per image: " << (elapsedTime / NB_OF_IMAGES) << " milliseconds" << std::endl; 
    #endif

    for(unsigned int incr = 0; incr < NB_OF_IMAGES; incr++) {
        delete i[incr]; 
    }

    exit(EXIT_SUCCESS); 
}
