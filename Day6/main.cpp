#include <iostream>
#include <fstream>
#include <list>

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
 * Shifts the members of the array.
 * 
 * @param array The array to shift each member.
 * @param n The size of the array.
 */
template <class T>
void shift (T** array, int n) {
    T* temp = new T[n]{0};
    for (int j = 0; j < n; j++) temp[(j - 1 + n) % n] = (*array)[j];
    delete (*array);
    *array = temp;
}

int main () {
    long* fish = new long[9]{0};
    fstream* file = new fstream();
    file->open("input.txt");
    if (!file->is_open()) return -1; // Failed to open file.
    string input;
    *file >> input;
    for (int i = 0; i < (input.size() + 1) / 2; i++) {
        int n = getInt(',', i, input);
        fish[n]++;
    }
    // ---- Part 1 ----
    for (int day = 1; day <= 80; day++) {
        long i = fish[0];
        shift(&fish, 9);
        fish[6] += i;
        fish[8] = i;
    }
    long count = 0;
    for (int i = 0; i < 9; i++) count += fish[i];
    cout << "The Population after 80 Days is: " << count << endl;
    // ---- Part 2 ----
    // A new fish on day n, will produce a + 1 new fish where 8 + 6(a) <= m, and 8 + 6(a+1) > m
    for (int day = 81; day <= 256; day++) {
        long i = fish[0];
        shift(&fish, 9);
        fish[6] += i;
        fish[8] = i;
    }
    count = 0;
    for (int i = 0; i < 9; i++) count += fish[i];
    cout << "The Population after 256 Days is: " << count << endl;
    return 0;
}
