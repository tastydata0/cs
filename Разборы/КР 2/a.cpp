#include <iostream>

using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> b >> a;

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        a += t;
    }

    cout << a % b << endl;
}