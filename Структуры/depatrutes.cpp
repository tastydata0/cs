#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
    // Если не работает на винде, пишите system("cls");
}

void redner(vector<Departure>* departures) {
    SimpleTime currentTime = getLocaltime();

    int printed = 0;
    for (int i = 0; i < departures->size() && printed <= 10; i++) {
        if (!(departures->at(i)._time < currentTime)) {
            departures->at(i).print();
            printed++;
        }
    }
}

void updateInfinitely(vector<Departure>* departures, int delayMilliseconds) {
    while (true) {
        clearScreen();
        redner(departures);
        cout << "Updating..." << endl;
        this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));
    }
}

struct SimpleTime {
    int hour;
    int minute;

    // SimpleTime(int h, int m) {
    //     hour = h;
    //     minute = m;
    // }

    string toString() const {
        stringstream ss;
        ss << setw(2) << setfill('0') << hour << ":"
           << setw(2) << setfill('0') << minute;
        return ss.str();
    }

    bool operator<(const SimpleTime& other) const {
        if (hour == other.hour) 
            return minute < other.minute;
        else 
            return hour < other.hour;
    }
};

struct Departure {
    SimpleTime _time;   // Время вылета
    int id;             // Номер рейса
    string destination; // Направление
    string gate;        // Выход

    Departure() {}

    Departure(const vector<string>* cities) {
        _time.hour = rand() % 24;
        _time.minute = rand() % 60;
        id = rand() % 10000;
        gate = (char)('A' + rand() % 5) + to_string(rand() % 50 + 1);
        destination = cities->at(rand() % cities->size());
    }

    void print() {
        cout << "| " << setw(4) << left << id << " | ";
        cout << _time.toString() << " | ";
        cout << setw(20) << left << destination << " | ";
        cout << setw(4) << left << gate << " |" << endl;
        cout << "|------|-------|----------------------|------|" << endl;

    }

    bool operator<(const Departure& other) const {
        return _time < other._time;
    }
};

void printHeader() {
    cout << "|  ID  | TIME  | DESTINATION          | GATE |" << endl;
    cout << "|------|-------|----------------------|------|" << endl;
}

vector<string>* readCities() {
    vector<string>* cities = new vector<string>;
    ifstream fin("cities.txt");

    string buffer;
    while(getline(fin, buffer))
        cities->push_back(buffer);

    fin.close();

    return cities;
}

SimpleTime getLocaltime() {
    time_t rawtime = time(0);
    tm* timeinfo = localtime(&rawtime);
    int hours = timeinfo->tm_hour;
    int minutes = timeinfo->tm_min;

    return {hours, minutes};
}

int main() {
    srand(time(0)); // Устанавливаем сид, равный системному времени

    vector<string>* cities = readCities();

    vector<Departure>* departures = new vector<Departure>(500);

    printHeader();
    for (Departure& d : *departures) 
        d = Departure(cities);
    
    sort(departures->begin(), departures->end());

    
     cout << "\033[1;31mbold red text\033[0m\n";
    
    delete departures;
    delete cities;
}
