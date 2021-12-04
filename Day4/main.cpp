#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char** argv) {

    string filename = "example.txt";

    if (argc >= 2) filename = argv[1];

    ifstream* file = new ifstream();
    if (file->is_open()) return -1;
    file->open(filename);

    return 0;
}