#include <stdlib.h>
#include <stdio.h>

typedef struct Sensor {

    int sX;
    int sY;
    int bX;
    int bY;

} Sensor;

int manhattanDist (int aX, int aY, int bX, int bY) {
    return abs(aX - bX) + abs(aY - bY);
}

int manhattanDistBeacon (Sensor s) {
    return abs(s.sX - s.bX) + abs(s.sY - s.bY);
}

/**
 * @return 1 - Closer than beacon.
 *         0 - Further than beacon. 
 */
short isCloserThanBeacon (Sensor s, int aX, int aY) {
    int beacon = manhattanDistBeacon(s);
    int toThisPoint = manhattanDist(s.sX, s.sY, aX, aY);
    if (toThisPoint <= beacon) return 1;
    return 0;
}

void resize (Sensor** arr, Sensor insert, int length) {
    Sensor* temp = (Sensor*) malloc(sizeof(Sensor) * (length + 1));
    for (int i = 0; i < length; i++) {
        printf("%i ", i);
        temp[i] = (*arr)[i];
    }
    free(*arr);
    temp[length] = insert;
    *arr = temp;
}

int readInt (FILE* file) {
    char c = fgetc(file);
    int current = 0;
    short negative = 0;

    while (((c <= '9' && c >= '0') || c == '-') && c != (char) EOF ) {
        if (c != '-') {
            current *= 10;
            current += c - '0';
        } else negative = 1;
        c = fgetc(file);
    }

    if (negative == 1) current *= -1;

    return current;
}

int main () {

    char* filename = "./input.txt";
    int query_row = 2000000;
    FILE* file = fopen(filename, "r");
    char c = fgetc(file);
    int length = 0;
    Sensor* sensors = (Sensor*) malloc(sizeof(Sensor) * 0);
    short val = 0;
    int* values = (int*) malloc(sizeof(int) * 4);

    while (c != (char) EOF) {
        c = fgetc(file);
        if (c == '=') {
            switch (val) {
                default:
                    values[val] = readInt(file);
                    val++;
                    break;
                case 3:
                    values[val] = readInt(file);
                    Sensor s;
                    s.sX = values[0];
                    s.sY = values[1];
                    s.bX = values[2];
                    s.bY = values[3];
                    resize(&sensors, s, length);
                    length++;
                    val = 0;
                    break;
            } 
        }
    }

    int maxBeaconX = 0;
    int maxSensorX = 0;

    for (int i = 0; i < length; i++) {
        Sensor s = sensors[i];
        printf("Sensor: <%i, %i>, Beacon: <%i, %i>\n", s.sX, s.sY, s.bX, s.bY);
        if (s.sX > maxSensorX) maxSensorX = s.sX;
        if (s.bX > maxBeaconX) maxBeaconX = s.bX;
    }

    printf("Checking -%i --> %i\n", maxBeaconX + maxSensorX, maxBeaconX + maxSensorX);

    long sum = -1;

    for (int i = -1 * (maxBeaconX + maxSensorX); i < maxBeaconX + maxSensorX; i++) {
        for (int j = 0; j < length; j++) {
            if (isCloserThanBeacon(sensors[j], i, query_row) == 1) {
                sum++;
                break;
            }
        }
    }

    printf("Cells Covered: %ld\n", sum);

    int solutionX = -1;
    int solutionY = -1;
    long long step = 0;
    long long fullSteps = 4000000 * 4000000;
    long long increment = fullSteps / 90;
    printf("Increment: %lld\n", increment);


    for (int i = 0; i < 4000000; i++) {
        if (solutionX + solutionY != -2) break;
        for (int j = 0; j < 4000000; j++) {
            if (solutionX + solutionY != -2) break;
            int close = 0;
            for (int k = 0; k < length; k++) {
                while (isCloserThanBeacon(sensors[k], i, j) == 1) {
                    close = 1;
                    break;
                }
            }
            step += 1;
            if (step >= increment) {
                printf("=");
                step = 0;
            }
            if (close == 0) {
                solutionX = i;
                solutionY = j;
                break;
            }
        }
    }
    printf("\n");
    printf("(%i, %i) => %ld\n", solutionX, solutionY, (solutionX * 4000000) + solutionY);

    return 0;
}
