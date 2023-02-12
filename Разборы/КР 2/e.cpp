#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int a[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += a[i][i] + a[i][n-1-i] * (i != n-1-i);
        cout << res << endl;
    }

    while(m--) {
        int t; cin >> t;
        if(res == t) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

}