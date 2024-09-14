#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned char proximo(unsigned char* a, unsigned int i, unsigned int j, unsigned char regla, unsigned int N) {

}


void print_state(int** state_matrix, const int cell_number, const int row) {
    for (int i = 0; i < cell_number; i++) {
        printf("%d ", state_matrix[row][i]);
    }
    printf("\n");
}

void load_initial_state(int** state_matrix, char* filename, const int cell_number) {
    // Habria que leer el archivo de entrada y popular la linea 0 de state_matrix
    //FILE* file = fopen(filename, "r");
    //Estado default 000010000
    state_matrix[0][4] = 1;
    printf("Initial state is:\n");
    print_state(state_matrix, cell_number, 0);
    return;
}

int* create_vector_for_rule(int rule_number) {
    // Crea y devuelve un vector de 1s y 0s a partir del numero de regla recibido
    //
    // Por ejemplo, para el numero de regla 30
    // {0, 0, 0, 1, 1, 1, 1, 0}
    // Para el numero de regla 100
    // {0, 1, 1, 0, 0, 1, 0, 0}
    int* rule_vector = calloc(8, sizeof(int));
    for (int i = 7; i > -1; i--) {
        int binary = pow(2, i);
        if (binary > rule_number) {
            rule_vector[i] = 0;
        } else {
            rule_number -= binary;
            rule_vector[i] = 1;
        }
    }
    return rule_vector;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Insufficient key arguments");
        return 0;
    }
    const int rule_number = atoi(argv[1]);
    const int cell_number = atoi(argv[2]);
    char* filename = argv[3];
    int** state_matrix = calloc(cell_number, sizeof(int*));
    if (state_matrix == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < cell_number; i++) {
        int* state = calloc(cell_number, sizeof(int));
        state_matrix[i] = state;
    }

    load_initial_state(state_matrix, filename, cell_number);

    for (int i = 1; i < cell_number; i++) {
        // for (int j = 0; j < cell_number; j++) {
        //     state_matrix[i][j] = proximo(state_matrix[0], i, j, rule_number, cell_number);
        // }
        printf("New state is:\n");
        print_state(state_matrix, cell_number, i);
    }

    int* rule_vector = create_vector_for_rule(rule_number);
    free(rule_vector);
    free(state_matrix);
    return 0;
}
