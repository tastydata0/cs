#include <vector>
#include <iostream>

using namespace std;
vector<int> n(vector<int>& a)
{
    vector<int> b;
    int q = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (a[i] == a[j])
                q++;
        }
        if (q == 0)
            b.push_back(a[i]);
        q = 0;
    }
    return b;
}

int main()
{
    vector<int> a{ 1,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9, 9, 1, 2 };
    a = n(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    return 0;
}