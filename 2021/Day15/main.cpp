#include <iostream>
#include <fstream>

using namespace std;

int main () {
    fstream* file = new fstream();
    file->open("input.txt");
    if (!file->is_open()) return -1;
    string line;
    *file >> line;
    const int a = line.length();
    int** matrix = new int*[a];
    int row = 0;
    while (!file->eof()) {
        matrix[row] = new int[a];
        if (row != 0) *file >> line;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '\n') break;
            matrix[row][i] = line[i] - '0';
        }
        row++;
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) cout << matrix[i][j];
        cout << endl;
    }
}