#include <iostream>

using namespace std;

int main() {
    unsigned int n, res = 0;
    cin >> n;

    while (n) {
        res += (n & 0b11) == 0b11;
        n >>= 1;
    }

    cout << res << endl;
}