#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream name("name.txt");
    ifstream surname("surname.txt");
    ifstream patronymic("patronymic.txt");

    vector<string> fios;

    string n, s, p;
    while(getline(name, n)
        && getline(surname, s) 
        && getline(patronymic, p)) {
        fios.push_back(s + " " + n + " " + p);
        cout << s + " " + n + " " + p << endl;
    }
    sort(fios.begin(), fios.end());

    ofstream result("result.txt");
    for(string fio : fios) {
        result << fio << endl;
    }

    result.close();

    name.close();
    surname.close();
    patronymic.close();
}