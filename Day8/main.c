#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"

int main () {
    FILE* file = fopen("input.txt", "r");
    char c = '0';
    int count = 0;
    int temp = 0;
    while (c != EOF) {
        // Iterate over the first section
        while (c != '|' && c != EOF) c = fgetc(file);
        c = fgetc(file); // ' '
        c = fgetc(file); // First letter
        while (c != '\n' && c != EOF) {
            temp = 0;
            while (c != ' ' && c != '\n' && c != EOF) {
                temp++;
                c = fgetc(file);
            }
            if (temp == 2 || temp == 3 || temp == 7 || temp == 4) count++;
            if (c == ' ') c = fgetc(file);
        }
    }
    fclose(file);
    printf("1, 4, 7, and 8 show up %d times.", count);
    return 0;
}
