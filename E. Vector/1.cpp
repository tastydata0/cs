#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int size = 10;

    vector<int> v(size, 1);

    for (int i = 0; i < v.size(); i++)
        cin >> v[i];

    int sum = 0;

    for(int a : v)
        sum += a;

    cout << sum << " " << sum / (double)size << endl;
}