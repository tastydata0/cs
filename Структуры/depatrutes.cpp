#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
    // Если не работает на винде, пишите system("cls");
}

void updateInfinitely(int delayMilliseconds) {
    while (true) {
        clearScreen();
        cout << "Updating..." << endl;
        this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));
    }
}

pair<int, int> getLocaltime() {
    time_t rawtime = time(0);
    tm* timeinfo = localtime(&rawtime);
    int hours = timeinfo->tm_hour;
    int minutes = timeinfo->tm_min;

    return {hours, minutes};
}

int main() {
    updateInfinitely(1000);
}