#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"

int main () {
    FILE* file = fopen("input.txt", "r");
    char*** inputs = malloc(sizeof(char*) * 7); // This will store each char array by length
    for (int i = 0; i < 7; i++) inputs[i] = malloc(sizeof(char*) * 3);
    int* counts = malloc(sizeof(int) * 7);
    for (int i = 0; i < 7; i++) counts[i] = 0;
    char* word = malloc(sizeof(char) * 7);
    char c = '0';
    int count = 0;
    while (c != EOF) {
        int temp = 0;
        free(word);
        free(counts);
        word = malloc(sizeof(char) * 7);
        counts = malloc(sizeof(int) * 7);
        for (int i = 0; i < 7; i++) counts[i] = 0;
        while (c != '|' && c != EOF) {
            c = fgetc(file);
            if ((c == ' ' || c == '\n') && temp > 1) {
                inputs[temp - 1][counts[temp - 1]] = word;
                counts[temp - 1]++;
                temp = 0;
                word = malloc(sizeof(char) * 7);
            } else {
                word[temp] = c;
                temp++;
            }
        }
        Cipher* cipher = createCipher(inputs[1][0], inputs[3][0], inputs[2][0], inputs[6][0]);
        solveCipher(inputs[4], inputs[5], cipher);
        int num = 0;
        while (c != '\n' && c != EOF) {
            c = fgetc(file);
            char* decode = malloc(sizeof(char) * 7);
            int decodeSize = 0;
            while (c != ' ' && c != EOF && c != '\n') {
                decode[decodeSize] = c;
                decodeSize++;
                c = fgetc(file);
            }
            if (decodeSize > 0) {
                num *= 10;
                num += solve(decode, decodeSize, cipher);
            }
            free(decode);
        }
        count += num;
    }
    printf("Essential Display Values: %d", count);
    fclose(file);
    return 0;
}
