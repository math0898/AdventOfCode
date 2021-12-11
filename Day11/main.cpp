#include <iostream>
#include "Octo.cpp"

using namespace std;

int main () {
    OctoGrid* octoGrid = new OctoGrid("input.txt");
    octoGrid->print();
    long flashes = 0;
    int day = 0;
    bool synced;
    while (day <= 99) {
        octoGrid->energy();
        flashes += octoGrid->flash();
        day++;
    }
    cout << "The Octopi flashed " << flashes << " times in 100 steps." << endl;
    while (!synced) {
        day++;
        octoGrid->energy();
        octoGrid->flash();
        synced = octoGrid->checkSynced();
    }
    cout << "The Octopi synced up on day " << day << endl;
    delete(octoGrid);
    return 0;
}
