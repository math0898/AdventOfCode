#include <iostream>
#include <fstream>

using namespace std;

int arr_length = 14; // 4 for pt1, 14 for pt2

bool containsDupe (char* arr) {
    for (int i = 0; i < arr_length; i++)
        for (int j = i + 1; j < arr_length; j++)
            if (arr[i] == arr[j])
                return true;
    return false;
}

char* shift (char* buffer, char insert) {
    char* temp = new char[arr_length];
    for (int i = 1; i < arr_length; i++) temp[i - 1] = buffer[i];
    temp[arr_length - 1] = insert;
    delete(buffer);
    return temp;
}

int main () {

    fstream* file = new fstream("./input.txt");

    char* buffer = new char[arr_length];
    for (int i = 0; i < arr_length; i++) buffer[i] = file->get();
    int read = arr_length;

    while (buffer[arr_length - 1] != (char) EOF && containsDupe(buffer)) {
        read++;
        buffer = shift(buffer, file->get());
    }

    cout << "Found: ";
    for (int i = 0; i < arr_length; i++) cout << buffer[i];
    cout << " After: " << read << " Characters." << endl;

    return 0;
}
