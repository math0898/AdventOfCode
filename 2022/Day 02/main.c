#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char opp; // Opponent
    char play;
} RPS_ROUND;

RPS_ROUND createRPS (char opp, char play) {
    RPS_ROUND r;
    r.opp = opp;
    r.play = play;
    return r;
}

int calcRPS (RPS_ROUND round) {
    if (round.opp == round.play) return 3 + round.play + 1;
    if ((round.opp + 1) % 3 == round.play) return 6 + round.play + 1;
    return 0 + round.play + 1;
}

int outRPS (RPS_ROUND round) {
    int p = 0;
    switch (round.play) {
        case 0: 
            p = (round.opp + 2) % 3;
            return 0 + p + 1;
        case 1:
            p = (round.opp);
            return 3 + p + 1;
        case 2:
            p = (round.opp + 1) % 3;
            return 6 + p + 1;
    }
    return 0;
}

/**
 * Resizes the given array to accept the number number i.
 * 
 * @param array The array to resize.
 * @param n The number of elements currently in the array.
 * @param i The element to add.
 */
void resize (RPS_ROUND** array, int n, RPS_ROUND i) {
    RPS_ROUND* temp = malloc(sizeof(RPS_ROUND) * (n + 1));
    for (int j = 0; j < n; j++) temp[j] = (*array)[j];
    temp[n] = i;
    free(*array);
    *array = temp;
}

int main () {
    FILE* file = fopen("./input.txt", "r");
    RPS_ROUND* rounds = malloc(0);
    int length = 0;

    char in = fgetc(file);

    while (in != EOF) {
        char opp = in - 'A'; // byte 1
        fgetc(file); // Always ' '
        char play = fgetc(file) - 'X'; // Byte 3

        resize(&rounds, length, createRPS(opp, play));
        length++;

        fgetc(file); // \n
        in = fgetc(file); // First char next line
    }

    int running_sum = 0;
    for (int i = 0; i < length; i++) running_sum += calcRPS(rounds[i]);
    
    printf("\nFinal Sum is: %i\n", running_sum);

    running_sum = 0;
    for (int i = 0; i < length; i++) {
        running_sum += outRPS(rounds[i]);
        printf("%i vs %i: %i\n", rounds[i].opp, rounds[i].play, outRPS(rounds[i]));
    }
    
    printf("chicken\n");
    printf("\nFinal Sum For L/T/W is: %i\n", running_sum);

    return 0;
}
