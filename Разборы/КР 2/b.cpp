#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int sum = 0, count = 0, mn = 1001, mx = -1001;
    while(t) {
        mn = min(mn, t);
        mx = max(mx, t);
        sum += t;
        count++;
        cin >> t;
    } 

    cout << (double)sum / count << " " << mn << " " << mx << endl;
}