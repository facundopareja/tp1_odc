#include <stdio.h>
#include <stdlib.h>
#include "pbm_writer.h"

unsigned char proximo(unsigned char** state_matrix, unsigned int i, unsigned int j, unsigned char regla, unsigned int N) {
    unsigned char left_neighbor;
    unsigned char cell = state_matrix[i][j];
    unsigned char right_neighbor;
    if (j == 0) {
        left_neighbor = state_matrix[i][N-1];
    }
    else {
        left_neighbor = state_matrix[i][j-1];
    }
    if (j == N-1) {
        right_neighbor=state_matrix[i][0];
    }
    else {
        right_neighbor = state_matrix[i][j+1];
    }
    int bit_number = 4 * left_neighbor + 2 * cell + right_neighbor;
    return (regla & ( 1 << bit_number )) >> bit_number;
}


void print_state(unsigned char** state_matrix, const unsigned int cell_number, const unsigned int row) {
    for (int i = 0; i < cell_number; i++) {
        printf("%d ", state_matrix[row][i]);
    }
    printf("\n");
}

void load_initial_state(unsigned char** state_matrix, char* filename, unsigned int cell_number) {
    FILE *file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
        printf("Error reading file\n");
        return;
    }
    char row[cell_number+1];
    fgets(row, cell_number+1, file_pointer);
    for (int i = 0; i < cell_number; i++) {
        state_matrix[0][i] = row[i]-'0';
    }
    printf("Initial state is:\n");
    print_state(state_matrix, cell_number, 0);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Insufficient key arguments");
        return 0;
    }
    const unsigned int rule_number = atoi(argv[1]);
    // check if rule is valid
    const unsigned int cell_number = atoi(argv[2]);

    char* filename = argv[3];
    unsigned char** state_matrix = calloc(cell_number, sizeof(unsigned char*));
    if (state_matrix == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < cell_number; i++) {
        unsigned char* state = calloc(cell_number, sizeof(char));
        state_matrix[i] = state;
    }

    load_initial_state(state_matrix, filename, cell_number);

    for (int i = 0; i < cell_number -1; i++) {
         for (int j = 0; j < cell_number; j++) {
             state_matrix[i+1][j] = proximo(state_matrix, i, j, rule_number, cell_number);
         }
        printf("New state is:\n");
        print_state(state_matrix, cell_number, i+1);
    }
    write_to_pbm(state_matrix, cell_number);
    free(state_matrix);
    return 0;
}
