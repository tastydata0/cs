#include <iostream>

using namespace std;

/*
Описать процедуру sort3(float, float, float), сортирующую последовательность из 3 вещественных значений. При этом результат нужно записать во входные переменные.
*/

// 3 2 1
// 2 3 1
// 2 1 3
// 1 2 3
void sort3(float &a, float &b, float &c)
{
    if(a > b)
        swap(a, b);
    
    if(b > c)
        swap(b, c);
    
    if(a > b)
        swap(a, b);
}

int main()
{
    float a = 3, b = 1, c = 2;
    sort3(a, b, c);
    cout << a << " " << b << " " << c << endl;
}