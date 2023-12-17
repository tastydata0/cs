# Сортировки

## 15 Sorting Algorithms in 6 Minutes

https://www.youtube.com/watch?v=kPRA0W1kECg


## Пузырьковая сортировка

Сортировка пузырьком (Bubble Sort) - это простой алгоритм сортировки, который многократно проходит по списку элементов и меняет местами соседние элементы, если они находятся в неправильном порядке. Процесс продолжается до тех пор, пока список не станет отсортированным.

<img src="https://github.com/tastydata0/cs/blob/main/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B8/Bubble%20Sort.gif"></img>

```cpp
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

                // Меняем местами, если бОльший элемент стоит раньше. Можно через swap
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
}
```

### Bubble sort with Hungarian, folk dance

<a>https://www.youtube.com/watch?v=Iv3vgjM8Pv4</a>
