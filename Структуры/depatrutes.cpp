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

const string GRAY = "\033[90m";
const string BLUE = "\033[94m";
const string CYAN = "\033[96m";
const string GREEN = "\033[92m";
const string WARNING = "\033[93m";
const string FAIL = "\033[91m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
const string ENDC = "\033[0m";

const int STATUS_NONE = 0;
const int STATUS_BOARDING = 1;
const int STATUS_CANCEL = 2;

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


SimpleTime getLocaltime() {
    time_t rawtime = time(0);
    tm* timeinfo = localtime(&rawtime);
    int hours = timeinfo->tm_hour;
    int minutes = timeinfo->tm_min;

    return {hours, minutes};
}


struct Departure {
    SimpleTime _time;        // Время вылета
    int id;                  // Номер рейса
    string destination;      // Направление
    string gate;             // Выход
    bool cancelled = false;  // Отменен ли рейс

    Departure() {}

    Departure(const vector<string>* cities) {
        _time.hour = rand() % 24;
        _time.minute = rand() % 60;
        id = rand() % 10000;
        gate = (char)('A' + rand() % 5) + to_string(rand() % 50 + 1);
        destination = cities->at(rand() % cities->size());

        // Отмена рейса с шансом 20%
        if (rand() % 10 <= 1) {
            cancelled = true;
        }
    }

    bool isBoarding() {

        // Время начала посадки: время вылета - 30 минут
        SimpleTime boardingTime = _time;
        boardingTime.minute -= 30;
        if (boardingTime.minute < 0) {
            boardingTime.hour--;
            boardingTime.minute += 60;
            if (boardingTime.hour == -1) {
                boardingTime.hour = 23;
            }
        }

        return !(getLocaltime() < boardingTime);
    }

    void print() {
        cout << "| " << setw(4) << left << id << " | ";
        cout << _time.toString() << " | ";
        cout << WARNING << BOLD << setw(20) << left << destination << ENDC << " | ";
        cout << setw(4) << left << gate << " | ";

        if (isBoarding() && !cancelled) 
            cout << BOLD << GREEN << setw(8) << "boarding" << ENDC;
         else if(cancelled) 
            cout << BOLD << FAIL << setw(8) << "canceled" << ENDC;
         else 
            cout << setw(8) << "";
        
        cout << " |" << endl;

        cout << "|------|-------|----------------------|------|----------|" << endl;
    }

    bool operator<(const Departure& other) const {
        return _time < other._time;
    }
};

void clearScreen() {
    cout << "\033[2J\033[1;1H";
    // Если не работает на винде, пишите system("cls");
}


void printHeader() {
    cout << "|  ID  | TIME  | DESTINATION          | GATE | STATUS   |" << endl;
    cout << "|------|-------|----------------------|------|----------|" << endl;
}

void redner(vector<Departure>* departures) {
    printHeader();

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


vector<string>* readCities() {
    vector<string>* cities = new vector<string>;
    ifstream fin("cities.txt");

    string buffer;
    while(getline(fin, buffer))
        cities->push_back(buffer);

    fin.close();

    return cities;
}


int main() {
    srand(time(0)); // Устанавливаем сид, равный системному времени

    vector<string>* cities = readCities();

    vector<Departure>* departures = new vector<Departure>(500);

    
    for (Departure& d : *departures) 
        d = Departure(cities);
    
    sort(departures->begin(), departures->end());

    updateInfinitely(departures, 1000);

    
    cout << "\033[1;31mbold red text\033[0m\n";
    
    delete departures;
    delete cities;
}
