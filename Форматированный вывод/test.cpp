#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //setlocale(LC_ALL, "");
    wstring a, b, c;
    for (int i = 0; i < 5; i++) {
        wcin >> a >> b >> c;
        wcout << right << setw(3) << i + 1 << "|";
        wcout << left << setw(12) << a << "|";
        wcout << left << setw(12) << b << "|";
        wcout << left << setw(12) << c << "|" << endl;
    }
    return 0;
}