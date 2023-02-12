#include <iostream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    int shift; cin >> shift;

    for(char c : line) {
        if('a' <= c && c <= 'z') {
            int letterIndex = c - 'a';
            letterIndex += shift;
            letterIndex %= 26;
            cout << (char)('a' + letterIndex);
        }
        else if('A' <= c && c <= 'Z') {
            int letterIndex = c - 'A';
            letterIndex += shift;
            letterIndex %= 26;
            cout << (char)('A' + letterIndex);
        }
        else if('0' <= c && c <= '9') {
            int letterIndex = c - '0';
            letterIndex += shift;
            letterIndex %= 10;
            cout << (char)('0' + letterIndex);
        }
        else {
            cout << c;
        }
    }
    cout << endl;
}