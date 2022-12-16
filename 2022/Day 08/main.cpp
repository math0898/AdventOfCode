#include <iostream>
#include <fstream>

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
template <class T>
void resize (T** array, T i, int n) {
    T *temp = new T[n + 1];
    for (int j = 0; j < n; j++) temp[j] = (*array)[j];
    temp[n] = i;
    delete(*array);
    *array = temp;
}

int main () {

    fstream* file = new fstream("./example.txt");
    char** board = new char*[1];
    int height = 1;
    int maxWidth = 0;
    int currentWidth = 0;
    int currentHeight = 0;

    while (!file->eof()) {
        char c = file->get();
        if (c == '\n') {
            resize(&board, new char[0], height);
            height++;
            currentHeight++;
            currentWidth = 0;
        } else if (c != (char) EOF) {
            if (currentWidth + 1 > maxWidth) maxWidth = currentWidth + 1;
            resize(&(board[currentHeight]), c, currentWidth);
            currentWidth++;
        }
    }

    // int potTrees = (height - 2) * (maxWidth - 2);
    int visible = 0;

    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < maxWidth - 1; j++) {
            char val = board[i][j];
            bool canSee = true;
            for (int k = 0; k < i; k++) {
                if (board[k][j] >= val)
                    canSee = false;
            }
            if (canSee) {
                visible++;
                continue;
            }
            for (int k = 0; k < j; k++) {
                if (board[i][k] >= val)
                    canSee = false;
            }
            if (canSee) {
                visible++;
                continue;
            }
            for (int k = maxWidth - 1; k > i; k--) {
                if (board[k][j] >= val)
                    canSee = false;
            }
            if (canSee) {
                visible++;
                continue;
            }
            for (int k = height - 1; k > j; k--) {
                if (board[i][k] >= val)
                    canSee = false;
            }
            if (canSee) {
                visible++;
                continue;
            }
        }
    }

    cout << "Found " << visible << " Visible Tree House Locations." << endl;

    return 0;
}