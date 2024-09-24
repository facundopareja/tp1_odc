#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pbm_writer.h"
#include "constants.h"
#include "input_parser.h"
#include <math.h>


unsigned char next_state(const unsigned char* state_matrix,
                         const unsigned int i, const unsigned int j,
                         unsigned char regla, const unsigned int N)
{
    unsigned char left_neighbor;
    const unsigned char cell = state_matrix[i * N + j];
    unsigned char right_neighbor;
    if (j == 0) {
        left_neighbor = state_matrix[(i + 1) * N - 1];
    }
    else {
        left_neighbor = state_matrix[(i * N) + j -1];
    }
    if (j == N-1) {
        right_neighbor=state_matrix[(i * N)];
    }
    else {
        right_neighbor = state_matrix[(i * N) + j + 1];
    }
    const int bit_number = 4 * left_neighbor + 2 * cell + right_neighbor;
    return (regla & ( 1 << bit_number )) >> bit_number;
}

int load_initial_state(unsigned char* state_matrix, const char* filename,
                       const unsigned int cell_number)
{
    FILE *file_pointer = fopen(filename, "r");

    if (file_pointer == NULL) {
        fprintf(stderr,"Error reading file\n");
        return EXIT_FAILURE;
    }
    printf("Reading initial state...\n");
    char row[cell_number+1];
    fgets(row, cell_number + 2, file_pointer);
    if (!feof(file_pointer)) {
        fprintf(stderr,"Cell number different from specified in input file\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < cell_number; i++) {
        state_matrix[i] = row[i]-'0';
    }
    return EXIT_SUCCESS;
}

int main(const int argc, char* argv[])
{
    if (parse_input(argc, argv) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (argc == 2) {
        return EXIT_SUCCESS;
    }
    const unsigned int rule_number = atoi(argv[1]);
    if (rule_number > MAX_RULE_NUMBER) {
        fprintf(stderr,"Invalid rule number\n");
        return EXIT_SUCCESS;
    }
    const unsigned int cell_number = atoi(argv[2]);
    const char* filename = argv[3];
    unsigned char* state_matrix = calloc(cell_number * cell_number, sizeof(unsigned char));
    if (state_matrix == NULL) {
        fprintf(stderr,"Memory allocation error");
        return 0;
    }
    if (load_initial_state(state_matrix, filename, cell_number) != EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    };
    char* pbm_filename = argv[3];
    if (argc == 6) {
        pbm_filename = argv[5];
    }
    strcat(pbm_filename, ".pbm");
    for (unsigned int i = 0; i < cell_number - 1; i++) {
        for (unsigned int j = 0; j < cell_number; j++) {
            const unsigned int cell_to_update = (i+1) * cell_number + j;
            state_matrix[cell_to_update] = next_state(state_matrix, i, j, rule_number, cell_number);
        }
    }
    if (write_to_pbm(state_matrix, cell_number, pbm_filename) != 0) {
        fprintf(stderr,"Error creating file");
    }
    free(state_matrix);
    return EXIT_SUCCESS;
}
