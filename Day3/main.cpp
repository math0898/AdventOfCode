#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

/**
 * Inserts the given item into the int array. Not ideal since it has to resize the int array nearly every time.
 *
 * The story behind this is I wanted a dynamically allocated structure but my friend would denounce me if I used vector.
 *
 * @param array The int array to resize.
 * @param i The int to add into the array.
 * @param n The length of the array.
 */
template <class T>
void resize (T** array, T i, int n) {
    T *temp = new T[n + 1];
    for (int j = 0; j < n; j++) temp[j] = (*array)[j];
    temp[n] = i;
    delete(*array);
    *array = temp;
}

/**
 * Duplicates the given array into the given pointer. This is a deep copy for primatives.
 * 
 * @param array The array to copy.
 * @param dest The array to override.
 * @param n The length of the array.
 */
template <class T>
void copyArray (T* array, T** dest, int n) {
    delete(*dest);
    *dest = new T[n];
    for (int i = 0; i < n; i++) (*dest)[i] = array[i];
}

/**
 * Converts the given string which represents a binary number into the corresponding decimal value.
 *
 * @param s The string to convert.
 * @return The decimal value of the given string.
 */
int convertBinary (string s) {
    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        r *= 2;
        if (s[i] == '1') r++;
    }
    return r;
}

/**
 * The main execution point of the program.
 */
int main () {
    string filename = "input.txt";
    ifstream *file = new ifstream();
    file->open(filename);
    if (!file->is_open()) return -1; // Failed to open file.
    string input;
    *file >> input;
    int *gammaCounts = new int[input.size()]{0};
    int elapsed = 1;
    for (int i = 0; i < input.size(); i++) if (input[i] == '1') gammaCounts[i]++;
    int length = input.size();
    int* oxygen = new int[1]{0};
    int size = 1;
    oxygen[0] = convertBinary(input);
    while (!file->eof()) {
        *file >> input;
        elapsed++;
        for (int i = 0; i < input.size(); i++) if (input[i] == '1') gammaCounts[i]++;
        resize(&oxygen, convertBinary(input), size);
        size++;
    }
    int* co2 = new int[0];
    copyArray(oxygen, &co2, size);
    int co2R = size;
    int oxygenR = size;
    for (int i = 1; i <= length; i++) {
        if (oxygenR != 1 || co2R != 1) {
            int oxyOnesCount = 0;
            int coOnesCount = 0;
            int power = pow(2, length - i); // This is the bit we are counting.
            for (int j = 0; j < size; j++) {
                if ((oxygen[j] & power) == power && oxygen[j] != -1) oxyOnesCount++;
                if ((co2[j] & power) == power && co2[j] != -1) coOnesCount++;
            }
            int oxyRequire = 0;
            int coRequire = 0;
            if (oxyOnesCount >= (oxygenR / 2.0)) oxyRequire = power;
            if (coOnesCount < (co2R / 2.0)) coRequire = power;
            for (int j = 0; j < size; j++) {
                if ((oxygen[j] & power) != oxyRequire && oxygen[j] != -1) {
                    oxygen[j] = -1;
                    oxygenR--;
                }
                else if ((co2[j] & power) != coRequire && co2R != 1 && co2[j] != -1) {
                    co2[j] = -1;
                    co2R--;
                }
            }
        }
    }
    string temp = "";
    for (int i = 0; i < input.size(); i++) { gammaCounts[i] > (elapsed / 2) ? temp += '1' : temp += '0'; }
    unsigned int gamma = convertBinary(temp);
    for (int i = 0; i < size; i++) {
        if (oxygen[i] != -1) {
            oxygen[0] = oxygen[i];
        }
        if (co2[i] != -1) {
            co2[0] = co2[i];
        }
    }
    cout << "The Power Consumption is: " << gamma * (~gamma % (int)pow(2, input.size())) << endl;
    cout << "Oxygen Generator Rating: " << oxygen[0] << endl;
    cout << "CO2 Scrubber Rating: " << co2[0] << endl;
    cout << "Life Support Rating: " << co2[0] * oxygen[0] << endl;
}
