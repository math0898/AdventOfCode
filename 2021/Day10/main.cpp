#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

/**
 * Returns the point score of the given bracket.
 * 
 * @param c The bracket to get the point score of.
 * @return The point value of the bracket.
 */
int scoreOfComplete (char c) {
    switch(c) {
        case ')': return 1;
        case ']': return 2;
        case '}': return 3;
        case '>': return 4;
    }
    return -1;
}

/**
 * Returns the point score of the given bracket.
 * 
 * @param c The bracket to get the point score of.
 * @return The point value of the bracket.
 */
int scoreOfCorrupt (char c) {
    switch (c) {
        case ')': return 3;
        case ']': return 57;
        case '}': return 1197;
        case '>': return 25137;
    }
    return -1;
}

/**
 * Returns the expected closing char based on the char passed to the function.
 * 
 * @param c The char to check for a closing char of.
 * @return The expecting closing char.
 */
char expectedClosing (char c) {
    switch (c) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        case '<': return '>';
    }
    return '0';
}

/**
 * Resizes the given array to accept the object i.
 * 
 * @param array The array to resize.
 * @param n The number of elements currently in the array.
 * @param i The element to add.
 */
template<class T>
void resize (T** array, int n, T i) {
    T* temp = new T[n + 1];
    for (int j = 0; j < n; j++) temp[j] = (*array)[j];
    temp[n] = i;
    delete(*array);
    *array = temp;
}

/**
 * Selection sort for that great O(n^2) runtime. Does it really matter though on 1k elements?
 * 
 * @param array The array sort.
 * @param n The length of the array to sort.
 */
template <class T>
void sort (T* array, int n) {
    int minIndex = 0;
    for (int i = 0; i < n; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) if (array[j] < array[minIndex]) minIndex = j;
        T temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main () {
    fstream* file = new fstream();
    file->open("input.txt");
    if (!file->is_open()) return -1;
    stack<char>* brackets = new stack<char>();
    long* completeScores = new long[0];
    int scores = 0;
    int score = 0;
    int corrupted;
    while (!file->eof()) {
        string input;
        *file >> input;
        corrupted = 0;
        for (char character : input) {
            if (character == '(' || character == '[' || character == '{' || character == '<') brackets->push(character);
            else if (character == '\n') continue;
            else {
                if (character != expectedClosing(brackets->top())) {
                    corrupted = 1;
                    score += scoreOfCorrupt(character);
                    break;
                }
                brackets->pop();
            }
        }
        if (corrupted == 0) {
            int size = 0;
            char* completion = new char[0];
            while (!brackets->empty()) {
                resize(&completion, size, expectedClosing(brackets->top()));
                brackets->pop();
                size++;
            }
            long temp = 0;
            for (int i = 0; i < size; i++) {
                temp *= 5;
                temp += scoreOfComplete(completion[i]);
            }
            resize(&completeScores, scores, temp);
            scores++;
            delete(completion);
        }
        while (!brackets->empty()) brackets->pop();
    }
    cout << "Corrupted bracket score: " << score << endl;
    sort(completeScores, scores);
    cout << "Completing brackets score: " << completeScores[scores / 2];
    return 0;
}