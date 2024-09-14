#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* create_vector_for_rule(int rule_number) {
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
    for (int i = 7; i > -1; i--) {
        printf("%d", rule_vector[i]);
    }
    return rule_vector;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Insufficient key arguments");
    }
    printf("%s\n", argv[3]);
    int rule_number = atoi(argv[1]);


    // reglas que requieren mas de 8 casilleros son invalidas

    // crear vector de 1s y 0s que represente la regla en binario, completando los casilleros
    // de la izquierda con 0s.

    int* rule_vector = create_vector_for_rule(rule_number);
    free(rule_vector);
}
