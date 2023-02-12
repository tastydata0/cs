#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[35][35];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int l; cin >> l;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt = 0;
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0) {
                cnt++;
                if(cnt >= l) {
                    cout << i+1 << endl;
                    return 0;
                }
            }
            else {
                cnt = 0;
            }
        }
    }
    cout << "NO" << endl;
}