#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    if(n & 1) cout << (n >> 4) << endl;
    else cout << (n & 0xF) << endl;
}