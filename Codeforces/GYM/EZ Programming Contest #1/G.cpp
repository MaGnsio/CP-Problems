/**
 *    author:  MaGnsi0
 *    created: 30/07/2021 02:14:30
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        //minimum
        if (n >= 15) {
            vector<int> v = {888, 108, 188, 200, 208, 288, 688};
            int y = (n - 1) / 7 - 2;
            cout << v[n % 7];
            for (int i = 0; i < y; ++i) {
                cout << 8;
            }
        } else {
            vector<int> v = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
            cout << v[n] << " ";
        }
        cout << " ";
        //maximum
        int x = n / 2;
        if (n & 1) {
            cout << 7;
            x--;
        }
        for (int i = 0; i < x; ++i) {
            cout << 1;
        }
        cout << "\n";
    }
}
