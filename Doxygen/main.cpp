#include "header.h"

int sum(int a, int b) {
    return a + b;
}

string* readFile(const string& filename) {
    ifstream fin(filename);

    string* result = new string;

    string buffer;
    while(getline(fin, buffer))
        result->append(buffer + "\n");

    fin.close();

    return result;
}

inline void createFile(const string& filename) {
    ofstream fout(filename);
    fout.close();
}

int main() {
    createFile("testFile.txt");
    string* fileContent = readFile("main.cpp");
    cout << *fileContent << endl;
    delete fileContent;
}