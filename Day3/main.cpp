#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

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

    string input;
    *file >> input;

    int* gammaCounts = new int[input.size()]{0};
    int elapsed = 1;
    for (int i = 0; i < input.size(); i++) if (input[i] == '1') gammaCounts[i]++;

    while (!file->eof()) {
        *file >> input;
        elapsed++;
        for (int i = 0; i < input.size(); i++) if (input[i] == '1') gammaCounts[i]++;
    }

    string temp = "";
    for (int i = 0; i < input.size(); i++) {
        if (gammaCounts[i] > (elapsed/2)) temp += '1';
        else temp += '0';
    }

    unsigned int gamma = convertBinary(temp);

    cout << "The Power Consumption is: " << gamma * (~gamma % (int) pow(2, input.size())) << endl;
}