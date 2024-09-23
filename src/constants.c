const int MAX_RULE_NUMBER = 255;

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