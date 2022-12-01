#include <fstream>
#include <iostream>

using namespace std;

string file_path = "./input.txt";

typedef struct {

    int* arr;
    int length;

} EasyArray;

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

int main () {

    fstream* file = new fstream(file_path, ios::in);
    int* input = new int[0];
    int length = 0;

    while (!file->eof()) {
        char* line = new char[100]{0};
        file->getline(line, 100);
        resize(&input, atoi(line), length);
        length++;
    }

    EasyArray* elf_sum = (EasyArray*) malloc(sizeof(EasyArray));
    elf_sum->length = 0;
    elf_sum->arr = (int *) malloc(0);

    for (int i = 0; i < length; i++) {
        int individual = 0;
        for ( ; i < length && input[i] != 0; i++) individual += input[i];
        resize(&(elf_sum->arr), individual, elf_sum->length);
        (elf_sum->length)++;
    }

    int max = 0;

    for (int i = 0; i < elf_sum->length; i++) 
        if (elf_sum->arr[i] > max) 
            max = elf_sum->arr[i];

    cout << "The Snack Hording Elf Has " << max << " Calories." << endl;

    int* topThree = new int[3]{0};

    for (int i = 0; i < elf_sum->length; i++) {
        for (int j = 2; j >= 0; j--) {
            if (elf_sum->arr[i] > topThree[j]) {
                topThree[j] = elf_sum->arr[i];
                break;
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = j; k < 3; k++) {
                if (topThree[j] < topThree[k]) {
                    int tmp = topThree[j];
                    topThree[j] = topThree[k];
                    topThree[k] = tmp;
                }
            }
        }
    }

    cout << "The Snack Hording Elves Have " << topThree[0] + topThree[1] + topThree[2] << " Calories combined." << endl;

    return 0;
}
