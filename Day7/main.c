#include <stdio.h>
#include <stdlib.h>

/**
 * Resizes the given array to accept the number number i.
 * 
 * @param array The array to resize.
 * @param n The number of elements currently in the array.
 * @param i The element to add.
 */
void resize (int** array, int n, int i) {
    int* temp = malloc(sizeof(int) * (n + 1));
    for (int j = 0; j < n; j++) temp[j] = (*array)[j];
    temp[n] = i;
    free(*array);
    *array = temp;
}

/**
 * Selection sort for that great O(n^2) runtime. Does it really matter though on 1k elements?
 * 
 * @param array The array sort.
 * @param n The length of the array to sort.
 */
void sort (int* array, int n) {
    int minIndex = 0;
    for (int i = 0; i < n; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) if (array[j] < array[minIndex]) minIndex = j;
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

/**
 * Preforms what can only be called an addition factorial and returns the value.
 * 
 * @param n The integer to calculate the addition factorial of.
 */
int additionFactorial (int n) {
    int count = 0;
    for (int i = n; i > 0; i--) count += i;
    return count;
}

int main (int argc, char** argv) { // test every fuel value.
    FILE* file = fopen("input.txt", "r");
    int length = 0;
    int* array = malloc(sizeof(int) * 0);
    char c = '0';
    int temp = 0;
    while (c != EOF) {
        c = fgetc(file);
        if (c == ',' || c == EOF) {
            resize(&array, length, temp);
            length++;
            temp = 0;
        } else {
            temp *= 10;
            temp += c - '0';
        }
    }
    resize(&array, length, temp);
    sort(array, length);
    int optimal = array[length / 2];
    printf("Optimal position for part 1 is: %d\n", optimal);
    int count = 0;
    // Ternary abuse.
    for (int i = 0; i < length; i++) count += (array[i] < optimal ? optimal - array[i] : array[i] - optimal);
    printf("Costing %d fuel for part 1.\n", count);
    int sum = 0;
    for (int i = 0; i < length; i++) sum += (array[i]);
    int average = sum / length;
    printf("Optimal position for part 2 is: %d\n", average);
    count = 0;
    // More ternary abuse.
    for (int i = 0; i < length; i++) count += additionFactorial(array[i] < average ? average - array[i] : array[i] - average);
    printf("Costing %d fuel for part 2.\n", count);
    fclose(file);
}
