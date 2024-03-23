#include <iostream>
#include <fstream> // Порубаем fstream

using namespace std;

int main() {
    // Все файлы должны лежать в одной папке с программой.
    // Открываем файл на чтение (ifstream). Название этой переменной используем вместо cin.
    ifstream fin("input.txt");
    int n; fin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    // Прочитать строку целиком, вместе со всеми пробелами. Работает аналогично и с cin.
    char endline; fin.get(endline); // Читаем символ перевода строки, чтобы getline не съела его.
    string s;
    getline(fin, s); // Читаем строку целиком.
    cout << s << endl;

    // Открываем файл на запись (ofstream). Название этой переменной используем вместо cout.
    ofstream fout("output.txt");
    for (int i = n-1; i >= 0; i--) {
        fout << a[i] << " ";
    }

    // P. S. Почему я назвал переменные fin и fout?


    // Чтение файла целиком
    ifstream fin2("text_fish.txt");
    string buffer;
    while(getline(fin2, buffer)) {
        cout << buffer << endl;
    }
}