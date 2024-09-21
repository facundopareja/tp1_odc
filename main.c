#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pbm_writer.h"
#include "constants.h"
#include "input_parser.h"

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

int load_initial_state(unsigned char** state_matrix, char* filename, unsigned int cell_number) {
    FILE *file_pointer = fopen(filename, "r");

    if (file_pointer == NULL) {
        printf("Error reading file\n");
        return EXIT_FAILURE;
    }
    printf("Reading initial state...\n");
    char row[cell_number+1];
    fgets(row, cell_number+2, file_pointer);
    if (!feof(file_pointer)) {
        printf("Cell number different from specified in input file\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < cell_number; i++) {
        state_matrix[0][i] = row[i]-'0';
    }
    printf("Initial state is:\n");
    print_state(state_matrix, cell_number, 0);
    return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
    if (parse_input(argc, argv) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    };
    const unsigned int rule_number = atoi(argv[1]);
    if (rule_number > MAX_RULE_NUMBER) {
        printf("Invalid rule number\n");
        return EXIT_SUCCESS;
    }
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
    if (load_initial_state(state_matrix, filename, cell_number) != EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    };
    char* pbm_filename = argv[3];
    if (argc == 6) {
        pbm_filename = argv[5];
    }
    strcat(pbm_filename, ".pbm");
    for (int i = 0; i < cell_number -1; i++) {
         for (int j = 0; j < cell_number; j++) {
             state_matrix[i+1][j] = proximo(state_matrix, i, j, rule_number, cell_number);
         }
    }
    if (write_to_pbm(state_matrix, cell_number, pbm_filename) != 0) {
        printf("Error creating file");
    }
    free(state_matrix);
    return EXIT_SUCCESS;
}
