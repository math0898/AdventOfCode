#include <iostream>
#include <fstream>
#include <list>
#include <string.h>

using namespace std;

int main (int argc, char** argv) {
    string filename = "example.txt";
    if (argc >= 2) filename = argv[1];
    ifstream* file = new ifstream();
    if (file->is_open()) return -1;
    file->open(filename);
    list<int>* numbers = new list<int>();
    char* inputs = new char[1000]{'a'};
    file->getline(inputs, 1000, '\n');
    char* read = new char[10]{'0'};
    read = strtok(inputs, ",");
    while (read != NULL) {
        numbers->push_back(atoi(read));
        read = strtok(inputs, ",");
    }

    while (numbers->size() > 0) {
        cout << (int) numbers->front() << endl;
        numbers->pop_front();
    }

    return 0;
}