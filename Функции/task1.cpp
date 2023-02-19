#include <iostream>

using namespace std;


int invDigits(int num)
{
    int res = 0;
    while(num) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }

    return res;
}

int main()
{
    cout << invDigits(12345) << endl;
    cout << invDigits(0) << endl;
    cout << invDigits(10000) << endl;
    cout << invDigits(1010) << endl;
}