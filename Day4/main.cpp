#include <iostream>
#include <fstream>

using namespace std;

int main () {

    ifstream* file = new ifstream();
    if (file->is_open()) return -1;
    file->open("example.txt");

    return 0;
}