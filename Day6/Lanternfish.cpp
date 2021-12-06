#include "Lanternfish.h"

Lanternfish::Lanternfish () {
    timer = 8;
}

void Lanternfish::passDay () {
    timer--;
    if (timer < 0) timer = 6;
}

int Lanternfish::getTimer () {
    return timer;
}
