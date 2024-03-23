#include <iostream>

using namespace std;

int addRightDigit(int a, int d)
{
    return a * 10 + d;
}

int main()
{
    int a = 123, d = 4;
    cout << addRightDigit(a, d) << endl;
}