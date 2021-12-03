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
void resize (int** array, int i, int n) {
    int* temp = new int[n + 1];
    for (int j = 0; j < n; j++) temp[j] = (*array)[j];
    temp[n] = i;
    delete(*array);
    *array = temp;
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

int main (int argc, char** argv) {
    ifstream* file = new ifstream();
    file->open("input.txt");

    if (!file->is_open()) return -1; // Failed to open file.

    // part 1
    // string input;
    // *file >> input;

    // int* gammaCounts = new int[input.size()]{0};
    // int elapsed = 1;
    // for (int i = 0; i < input.size(); i++) if (input[i] == '1') gammaCounts[i]++;

    // while (!file->eof()) {
    //     *file >> input;
    //     elapsed++;
    //     for (int i = 0; i < input.size(); i++) if (input[i] == '1') gammaCounts[i]++;
    // }

    // string temp = "";
    // for (int i = 0; i < input.size(); i++) {
    //     if (gammaCounts[i] > (elapsed/2)) temp += '1';
    //     else temp += '0';
    // }

    // unsigned int gamma = convertBinary(temp);

    // cout << "The Power Consumption is: " << gamma * (~gamma % (int) pow(2, input.size())) << endl;

    string input;
    *file >> input;
    int length = input.size();
    int* list = new int[1]{0};
    int size = 1;
    list[0] = convertBinary(input);
    while (!file->eof()) {
        *file >> input;
        resize(&list, convertBinary(input), size);
        size++;
    }

    int remaining = size;
    for (int i = 1; i <= length; i++) {
        if (remaining == 1) break;
        int onesCount = 0;
        int power = pow(2, length - i); // This is the bit we are counting.
        for (int j = 0; j < size; j++) {
            if (list[j] == -1) continue;
            if ((list[j] & power) == power) onesCount++;
        }
        int require = 0;
        if (onesCount >= (remaining/2.0)) require = power;
        cout << onesCount << "/" << remaining/2 << " Ones => " << require << endl;
        for (int j = 0; j < size; j++) {
            if (list[j] == -1) continue;
            if ((list[j] & power) != require) {
                list[j] = -1;
                remaining--;
            }
        }
        if (remaining < 4) {
            for (int j = 0; j < size; j++) if (list[j] != -1) cout << list[j] << endl;
        }
    }
    int oxygen = -1;
    for (int i = 0; i < size; i++) {
        if (list[i] != -1) {
            oxygen = list[i];
            break;
        }
    }
    cout << "Oxygen Generator Rating: " << oxygen << endl;

    list = new int[1]{0};
    size = 1;
    file->clear();
    file->seekg(0);
    *file >> input;
    list[0] = convertBinary(input);
    while (!file->eof()) {
        *file >> input;
        resize(&list, convertBinary(input), size);
        size++;
    }

    remaining = size;
    for (int i = 1; i <= length; i++) {
        if (remaining == 1) break;
        int onesCount = 0;
        int power = pow(2, length - i); // This is the bit we are counting.
        for (int j = 0; j < size; j++) {
            if (list[j] == -1) continue;
            if ((list[j] & power) == power) onesCount++;
        }
        int require = 0;
        if (onesCount < (remaining/2.0)) require = power;
        cout << onesCount << "/" << remaining/2.0 << " Ones => " << require << endl;
        for (int j = 0; j < size; j++) {
            if (list[j] == -1) continue;
            if ((list[j] & power) != require) {
                list[j] = -1;
                remaining--;
            }
        }
    }
    int carbon = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] != -1) {
            carbon = list[i];
            break;
        }
    }
    cout << "CO2 Scrubber Rating: " << carbon << endl;

    cout << "Life Support Rating: " << carbon * oxygen << endl;
}