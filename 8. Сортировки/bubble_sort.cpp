#include <iostream>

using namespace std;

int main() {
    // Пузырьковая сортировка
    int n = 5;
    int a[] = {19, 8, -5, 10, 9};
    // -5 8 9 10 19

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (a[j] > a[j+1]) {

                // Меняем местами, если бОльший элемент стоит раньше
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Как этот алгоритм можно ускорить?
}