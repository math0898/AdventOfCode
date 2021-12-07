#include <stdio.h>

int main (int argc, char** argv) {
    FILE* file = fopen("example.txt", "r");
    char c1 = fgetc(file);
    char* string = malloc(sizeof(char) * 100);
    fgets(&string, 100, file);
    fclose(file);
}