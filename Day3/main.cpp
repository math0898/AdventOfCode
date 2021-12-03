#include <fstream>
#include <iostream>

using namespace std;

int main () {
    ifstream* file = new ifstream();
    file->open("example.txt");

    if (!file->is_open()) return -1; // Failed to open file.

    cout << "Hello world" << endl;
}