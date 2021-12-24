#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Stack.c" // Needed to run from VSCode

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
    int node = 0;
    int startIndx = -1;
    int endIndx = -1;
    int** matrix = malloc(sizeof(int*) * 10);
    for (int i = 0; i < 10; i++) {
        matrix[i] = malloc(sizeof(int) * 10);
        for (int j = 0; j < 10; j++) matrix[i][j] = 0;
    }
    char** table = malloc(sizeof(char*) * 10);
    for (int i = 0; i < 10; i++) {
        table[i] = malloc(sizeof(char) * 2);
        table[i][0] = ' ';
        table[i][1] = ' ';
    }
    FILE* file = fopen("example1.txt", "r");
    char c = ' ';
    int index = 0;
    int lock = 0;
    char* buffer = malloc(sizeof(char) * 4);
    for (int i = 0; i < 4; i++) buffer[i] = ' ';
    while (c != EOF) {
        c = fgetc(file);
        if (c == '-') {
            lock = 1;
            index = 2;
        } else if (c == EOF || c == '\n') {
            for (int i = index; i < 4; i++) buffer[i] = ' ';
            char nodeFound = 0; // First two bits as booleans
            int srcIndex = 0;
            int destIndex = 0;
            for (int i = 0; i < node; i++) {
                if (table[i][0] == buffer[0] && table[i][1] == buffer[1]) {
                    srcIndex = i;
                    nodeFound |= 1;
                }
                if (table[i][0] == buffer[2] && table[i][1] == buffer[3]) {
                    destIndex = i;
                    nodeFound |= 2;
                }
            }
            if ((nodeFound & 1) == 0) {
                if (buffer[0] == 's' && buffer[1] == 't') startIndx = node;
                else if (buffer[0] == 'e' && buffer[1] == 'n') endIndx = node;
                table[node][0] = buffer[0];
                table[node][1] = buffer[1];
                srcIndex = node;
                node++;
            } 
            if ((nodeFound & 2) == 0) {
                if (buffer[2] == 's' && buffer[3] == 't') startIndx = node;
                else if (buffer[2] == 'e' && buffer[3] == 'n') endIndx = node;
                table[node][0] = buffer[2];
                table[node][1] = buffer[3];
                destIndex = node;
                node++;
            }
            matrix[srcIndex][destIndex] = 1;
            matrix[destIndex][srcIndex] = 1;
            index = 0;
            for (int i = 0; i < 4; i++) buffer[i] = ' ';
        } else if (index < 2 || (lock == 1 && index < 4)) {
            buffer[index] = c;
            index++;
        }
    }
    free(buffer);
    int paths = 0;
    Stack* toCheck = createStack();
    add(toCheck, startIndx);
    Stack* path = createStack();
    while (!isEmpty(toCheck)) {
        int current = pop(toCheck);
        if (current == endIndx) {
            paths++;
            printStack(path);
            continue;
        }
        add(path, current);
        for (int i = 0; i < 10; i++) {
            if (matrix[current][i] == 1) {
                if (!contains(path, i) || table[i][0] >= 'A') add(toCheck, i);
            }
        }
        // if (contains(path, current) && table[current][0] < 'A' ) {
        //     pop(path);
        //     // for (int i = 0; i < 10; i++) if (matrix[current][i] == -1) matrix[current][i] = 1;
        // } else {
        //     for (int i = 0; i< 10; i++) if (matrix[current][i] == 1 || (table[i][0] >= 'A' && matrix[current][i] == -1)) {
        //         add(toCheck, i);
        //         matrix[current][i] = -1;
        //     }
        //     add(path, current);
        // }
    }
    printMatrix(matrix, 6);
    for (int i = 0; i < 10; i++) printf("%d: %c%c\n", i, table[i][0], table[i][1]);
    for (int i = 0; i < 10; i++) {
        free(table[i]);
        free(matrix[i]);
    }
    free(table);
    free(matrix);
    fclose(file);
    printf("\n%d\n", paths);
    return 0;
}
