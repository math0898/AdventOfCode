#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char* c_str_copy (char* tocopy) {
    char* toReturn = new char[100]{ (char) NULL };
    for (int i = 0; i < 100; i++) toReturn[i] = tocopy[i];
    return toReturn;
}

int priority_value (char c) {
    if (c >= 'a') return (c - 'a') + 1;
    return (c - 'A') + 27;
}

char find_dupe_char (char* buffer) {
    char* dupes = new char[50]{ (char) NULL };
    int length = 0;
    for ( ; buffer[length] != (char) NULL; length++ );
    for (int i = length / 2; i < length; i++) 
        for (int j = 0; j < length / 2; j++) 
            if (buffer[i] == buffer[j]) 
                return buffer[i];
    return (char) -1; 
}

char find_badge_char (char* bag1, char* bag2, char* bag3) {
    for (int i = 0; i < 100 && bag1[i] != (char) NULL; i++) 
        for (int j = 0; j < 100 && bag2[j] != (char) NULL; j++) 
            if (bag2[j] == bag1[i])
                for (int k = 0; k < 100 && bag3[k] != (char) NULL; k++) 
                    if (bag3[k] == bag1[i]) return bag1[i];
    return (char) -1;
}

int main () {

    fstream* file = new fstream("./input.txt");
    int priority_sum = 0;
    int badges_sum = 0;
    int lines_read = 0;
    char* bag1 = new char[100]{ (char) NULL };
    char* bag2 = new char[100]{ (char) NULL };

    while (!file->eof()) {
        char* buffer = new char[100]{ (char) NULL };
        file->getline(buffer, 100, '\n');
        priority_sum += priority_value(find_dupe_char(buffer));
        lines_read++;
        switch (lines_read){
            case 1: 
                bag1 = c_str_copy(buffer);
                continue;
            case 2:
                bag2 = c_str_copy(buffer);
                continue;
            case 3:
                badges_sum += priority_value(find_badge_char(bag1, bag2, buffer));
                lines_read = 0;
                continue;
        }
    }

    cout << "The Priority Sum is: " << priority_sum << endl;
    cout << "The Badge Sum is: " << badges_sum << endl;

    file->close();
    delete(file);

    return 0;
}
