#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    string words[100];
    char minLetters[100];


    for(int i = 0; i < n; i++) {
        cin >> words[i];
        minLetters[i] = 'z';
        for(char c : words[i]) 
            minLetters[i] = min(minLetters[i], c);
    }

    for (char c = 'a'; c <= 'z'; c++) 
        for(int i = 0; i < n; i++)
            if(minLetters[i] == c) cout << words[i] << " ";
    
    cout << endl;

}