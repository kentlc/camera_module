/**
 * @file main.cpp
 * @author Olivier Desenfans
 * @brief CWIS camera acquisition software. 
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

#include <pthread.h>

#include "utils/utilities.hpp"

#include "image_buffer.h"

using namespace std; 

static inline void setDefaults(void); 

typedef struct {
    std::string outputDir; 
}ProgramOptions_s;

static image_buffer* images;
static ProgramOptions_s programOpts;

/* Long options definition */
static const struct option longOpts[] = {
    {"output-dir", required_argument, NULL, 'd'}
}; 

int main(int argc, char *argv[]) {

    int opt = 0;
    int longIndex = 0; 

    setDefaults();
    
    /* Command-line arguments parsing */
    while( (opt = getopt_long(argc, argv, "d:il", longOpts, &longIndex)) != -1) {

        switch (opt) {
            case 'd':
                programOpts.outputDir = optarg;
                break; 

            /* List all connected cameras and exit */
            case 'l':
                //exit(listConnectedCameras());
                break;
           
            /* Displays informations about the cameras */
            /** @todo Fix this and mix it with the -l option */
            case 'i':
                //exit(displayCameraInformations()); 
                break;

            /* Missing argument to an option */
            case ':':
                cerr << "Invalid option." << endl; 
                exit(EXIT_FAILURE);
                break; 

            /* Unknown argument, not specified in the optstring */
            case '?':
                break;

            /* Long option with no short option counterpart */
            case 0:
                break; 
        }
    }

    /* Acquisition */
	images = new image_buffer(CONFIG_AOI_WIDTH, CONFIG_AOI_HEIGHT, 
	                          CONFIG_BUFFER_SIZE);
	                          
	delete images;

    exit(EXIT_SUCCESS); 
}

static inline void setDefaults(void) {
    programOpts.outputDir = "images";
}

