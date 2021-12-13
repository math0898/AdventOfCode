#include <stdio.h>
#include <stdlib.h>

/**
 * Prints the given matrix to the console. The matrix should be square and 2 dimensional. The elements will be printed as ints.
 * 
 * @param array The array to print to console.
 * @param n The size of the array.
 */
void printMatrix (int** array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main () {
    int** matrix = malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++) matrix[i] = malloc(sizeof(int) * 10);
    printMatrix(matrix, 10);
    char** table = malloc(sizeof(char*) * 10);
    for (int i = 0; i < 10; i++) {
        table[i] = malloc(sizeof(char) * 2);
        table[i][0] = ' ';
        table[i][1] = ' ';
    }
    for (int i = 0; i < 10; i++) printf("%d: %c%c\n", i, table[i][0], table[i][1]);
    FILE* file = fopen("example1.txt", "r");
    char c = ' ';
    int index = 0;
    char* buffer = malloc(sizeof(char) * 2);
    while (c != EOF) {
        c = fgetc(file);
        if (c == '-' || c == EOF || c == '\n') {
            printf("%c%c\n", buffer[0], buffer[1]);
            index = 0;
            buffer[0] = ' ';
            buffer[1] = ' ';
        } else if (index < 2) {
            buffer[index] = c;
            index++;
        }
    }
    return 0;
}
