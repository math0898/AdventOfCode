#include <iostream>
#include <fstream>

using namespace std;

string filename = "input.txt";

/**
 * Returns the int value on one side of the delimantor. The int i determines how many delimanators to skip by first.
 * 
 * @param delim The delimantor to use.
 * @param i The number of delimantors to skip over.
 * @param s The string to be split apart.
 * @return The value of the int.
 */
int getInt (char delim, int i, string s) {
    int delimCount = 0;
    int r = 0;
    for (int j = 0; j < s.size(); j++) {
        if (delimCount == i) {
            if (s[j] == delim) break;
            r *= 10;
            r += s[j] - '0';
        }
        else if (s[j] == delim) delimCount++;
    }
    return r;
}

int main () {
    ifstream* file = new ifstream();
    file->open(filename);
    if (!file->is_open()) return -1; // Failed to open file.
    int board[1000][1000];
    for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) board[i][j] = 0;

    while (!file->eof()) {
        string p1, noise, p2;
        *file >> p1;
        *file >> noise;
        *file >> p2;
        int x1 = getInt(',', 0, p1);
        int y1 = getInt(',', 1, p1);
        int x2 = getInt(',', 0, p2);
        int y2 = getInt(',', 1, p2);
        if (x1 == x2) for (int i = (y1 < y2 ? y1 : y2); i <= (y1 < y2 ? y2 : y1); i++) board[i][x1]++;
        else if (y1 == y2) for (int i = (x1 < x2 ? x1 : x2); i <= (x1 < x2 ? x2 : x1); i++) board[y1][i]++;
        else {
            //We're dealing with one of part 2's diagonal lines.
            int x = x1;
            int y = y1;
            board[y1][x1]++;
            while (x != x2 && y != y2) {
                if (x < x2) x++;
                else x--;
                if (y < y2) y++;
                else y--;
                board[y][x]++;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) if (board[i][j] > 1) count++;
    cout << "The number of overlaps is: " << count << endl;
    return 0;
}