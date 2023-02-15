#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a = 3.14159265358979323846;
    cout << "a = " << a << endl;                     // a = 3.14159
    cout << "a = " << setprecision(10) << a << endl; // a = 3.1415926536
    cout << "a = " << setprecision(2) << a*100 << endl;  // a = 3.1
    return 0;
}