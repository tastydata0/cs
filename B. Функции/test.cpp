
#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}

float sum(float a, float b) {
    return a + b;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << sum(a, b) << endl;
    cout << sum(a, b, c) << endl;
    float x, y;
    cin >> x >> y;
    cout << sum(x, y) << endl;
    return 0;
}