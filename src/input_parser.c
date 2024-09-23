#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input_parser.h"
#include "constants.h"

int parse_input(int argc, char* argv[]) {
    if (argc == 2) {
        if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {
            printf("%s", HELP_MESSAGE);
            return EXIT_SUCCESS;
        }
        else if (strcmp("-V", argv[1]) == 0 || strcmp("--version", argv[1]) == 0) {
            printf("%s", VERSION_MESSAGE);
            return EXIT_SUCCESS;
        }
    }
    else if (argc == 4) {
        return EXIT_SUCCESS;
    }
    else if (argc == 6) {
        if (strcmp("-o", argv[4]) == 0) {
            return EXIT_SUCCESS;
        }
    }
    fprintf(stderr,"Invalid program arguments");
    return EXIT_FAILURE;
}