#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input_parser.h"

const char* HELP_MESSAGE = "Uso:\n"
               "autcel -h\n"
               "autcel -V\n"
               "autcel R N inputfile [-o outputprefix]\n"
               "Opciones:\n"
               "-h, --help\n"
               "Imprime este mensaje.\n"
               "-V, --version Da la versión del programa.\n"
               "-o Prefijo de los archivos de salida.\n"
               "Ejemplos:\n"
               "autcel 30 80 inicial -o evolucion\n"
               "Calcula la evolución del autómata \"Regla 30\",\n"
               "en un mundo unidimensional de 80 celdas, por 80 iteraciones.\n"
               "El archivo de salida se llamará evolucion.pbm.\n"
               "Si no se da un prefijo para los archivos de salida,\n"
               "el prefijo será el nombre del archivo de entrada.\n";

const char* VERSION_MESSAGE = "AUTCEL - Version 1.0\n";

int parse_input(int argc, char* argv[]) {
    if (argc == 2) {
        if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {
            printf("%s", HELP_MESSAGE);
        }
        else if (strcmp("-V", argv[1]) == 0 || strcmp("--version", argv[1]) == 0) {
            printf("%s", VERSION_MESSAGE);
        }
        else {
            printf("Unrecognized execution flag\n");
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
    else if (argc < 4) {
        printf("Insufficient key arguments");
        return EXIT_FAILURE;
    }
    if (argc == 6) {
        if (strcmp("-o", argv[4]) == 0) {
            return EXIT_SUCCESS;
        }
    }
    else {
        printf("Invalid program arguments");
    }
    return EXIT_FAILURE;
}