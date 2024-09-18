#include <stdio.h>
#include <stdlib.h>

void write_to_pbm(unsigned char** state_matrix, unsigned int cell_number) {
    char* filename = "file.pbm";
    FILE* file_pointer;
    file_pointer = fopen(filename, "w");
    // checking if the file is created
    if (file_pointer == NULL) {
        printf("Error opening file for writing");
        exit(0);
    }
    fprintf(file_pointer, "P1\n");
    fprintf(file_pointer, "# %s\n", filename);
    fprintf(file_pointer, "%d %d\n", cell_number, cell_number);
    for (int i = 0; i < cell_number; i++) {
        for (int j = 0; j < cell_number; j++) {
            fprintf(file_pointer, "%d", state_matrix[i][j]);
            if (j != cell_number-1) {
                fprintf(file_pointer, " ");
            }
        }
        fprintf(file_pointer, "\n");
    }
    printf("\n");
    fclose(file_pointer);
}