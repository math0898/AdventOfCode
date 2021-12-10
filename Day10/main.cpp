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
int scoreOf (char c) {
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

int main () {
    fstream* file = new fstream();
    file->open("input.txt");
    if (!file->is_open()) return -1;
    stack<char>* brackets = new stack<char>();
    int score = 0;
    while (!file->eof()) {
        string input;
        *file >> input;
        for (char character : input) {
            if (character == '(' || character == '[' || character == '{' || character == '<') brackets->push(character);
            else if (character == '\n') continue;
            else {
                if (character != expectedClosing(brackets->top())) {
                    score += scoreOf(character);
                    break;
                }
                brackets->pop();
            }
        }
        while (!brackets->empty()) brackets->pop();
    }
    cout << "Corrupted bracket score: " << score << endl;
    return 0;
}