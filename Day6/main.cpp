#include <iostream>
#include <fstream>
#include <list>
#include "Lanternfish.h"

using namespace std;

/**
 * Returns the int value on one side of the delimantor. The int i determines how many delimanators to skip by first. Copied from 
 * Day 5.
 * 
 * @param delim The delimantor to use.
 * @param i The number of delimantors to skip over.
 * @param s The string to be split apart.
 * @return The value of the int.
 */
int getInt (char delim, int i, string s) {
    int delimCount = 0;
    int r = 0;
    for (int j = 0; j < s.size(); j++) {
        if (delimCount == i) {
            if (s[j] == delim) break;
            r *= 10;
            r += s[j] - '0';
        }
        else if (s[j] == delim) delimCount++;
    }
    return r;
}

/**
 * Inserts the given item into the int array. Not ideal since it has to resize the int array nearly every time. Copied from 
 * Day 5.
 *
 * The story behind this is I wanted a dynamically allocated structure but my friend would denounce me if I used vector.
 *
 * @param array The int array to resize.
 * @param i The int to add into the array.
 * @param n The length of the array.
 */
template <class T>
void resize (T** array, T i, int n) {
    T* temp = new T[n + 1];
    for (int j = 0; j < n; j++) temp[j] = (*array)[j];
    temp[n] = i;
    delete (*array);
    *array = temp;
}

int main () {
    int length = 1;
    Lanternfish* fish = new Lanternfish[1];
    fstream* file = new fstream();
    file->open("input.txt");
    if (!file->is_open()) return -1; // Failed to open file.
    string input;
    *file >> input;
    fish[0] = Lanternfish(input[0] - '0');
    for (int i = 1; i < (input.size() + 1) / 2; i++) {
        int n = getInt(',', i, input);
        resize(&fish, Lanternfish(n), length);
        length++;
    }
    // Brute force solution. Linux + 24 GB of ram = GG
    for (int day = 1; day <= 80; day++) {
        int newFish = 0;
        for (int i = 0; i < length; i++) {
            if (fish[i].getTimer() == 0) newFish++;
            fish[i].passDay();
        }
        for (int i = 1; i <= newFish; i++) {
            resize(&fish, Lanternfish(), length);
            length++;
        }
        cout << "Day " << day << " has just passed." << endl;
    }
    cout << "The Population After 80 Days is: " << length << endl;
    return 0;
}