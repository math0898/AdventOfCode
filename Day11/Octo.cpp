#include <iostream>
#include <fstream>

using namespace std;

/**
 * OctoGrid... I don't think this needs anymore explanation.
 * 
 * @author Sugaku
 */
class OctoGrid {

    private:

        /**
         * @brief The actual grid that stores the energy value of the ocotpi.
         */
        int grid[10][10]{0}; // NO_WRAP

    public:

        /**
         * @brief Creates a new OctoGrid by reading the data in the given file.
         * 
         * @param filename The file to create the OctoGrid with.
         */
        OctoGrid (string filename) {
            fstream* file = new fstream();
            file->open(filename);
            if (!file->is_open()) return;
            for (int i = 0; i < 10; i++) {
                string line;
                *file >> line;
                for (int j = 0; j < 10; j++) grid[i][j] = line[j] - '0';
            }
        }

        /**
         * @brief Prints the OctoGrid to console.
         */
        void print () {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) cout << grid[i][j] << " ";
                cout << endl;
            }
        }

        /**
         * @brief Gives all the octopi 1 energy.
         */
        void energy () {
            for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) grid[i][j]++;
        }

        /**
         * @brief Flash all of the octopi. This will increase the energy of neighbors by 1 unless they're at 0 energy.
         * 
         * @return The number of flashes that occurred with this step.
         */
        int flash () {
            int flashes = 0;
            int temp = -1;
            while (flashes != temp) {
                temp = flashes;
                for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
                    if (grid[i][j] > 9) {
                        flashes++;
                        grid[i][j] = 0;
                        for (int di = -1; di <= 1; di++) for (int dj = -1; dj <= 1; dj++) {
                            if (i + di < 0 || i + di > 9 || j + dj < 0 || j + dj > 9) continue;
                            else if (grid[i + di][j + dj] != 0) grid[i + di][j + dj]++;
                        }
                    }
                }
            }
            return flashes;
        }

        /**
         * @brief Checks if the Octopi all flashed in sync last time around.
         * 
         * @return True if and only if all the Octopi flashed in sync.
         */
        bool checkSynced () {
            for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) if (grid[i][j] != 0) return false;
            return true;
        }
};
