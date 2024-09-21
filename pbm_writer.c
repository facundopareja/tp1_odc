#include <stdio.h>
#include <stdlib.h>

void write_row(unsigned char** state_matrix, FILE* file_pointer, unsigned int cell_number, unsigned int i) {
    for (int j = 0; j < cell_number; j++) {
        fprintf(file_pointer, "%d ", state_matrix[i][j]);
        fprintf(file_pointer, "%d", state_matrix[i][j]);
        if (j != cell_number-1) {
            fprintf(file_pointer, " ");
        }
    }

}

int write_to_pbm(unsigned char** state_matrix, unsigned int cell_number, char* pbm_filename) {
    FILE* file_pointer;
    file_pointer = fopen(pbm_filename, "w");
    if (file_pointer == NULL) {
        fprintf(stderr, "Error opening file for writing");
        return EXIT_FAILURE;
    }
    printf("Writing to %s", pbm_filename);
    fprintf(file_pointer, "P1\n");
    fprintf(file_pointer, "# %s\n", pbm_filename);
    fprintf(file_pointer, "%d %d\n", (int) 2*cell_number, (int) 2 * cell_number);
    for (int i = 0; i < cell_number; i++) {
        write_row(state_matrix, file_pointer, cell_number, i);
        write_row(state_matrix, file_pointer, cell_number, i);
        fprintf(file_pointer, "\n");
    }
    printf("\n");
    fclose(file_pointer);
    return 0;
}