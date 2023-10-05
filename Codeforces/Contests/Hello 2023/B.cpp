/**
 *    author:  MaGnsi0
 *    created: 03.01.2023 16:49:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << (i & 1 ? -1 : 1) << " ";
            }
            cout << "\n";
            continue;
        }
        int a = -1, b = -1;
        for (int i = 1; i <= 5000; ++i) {
            int x = n / 2 - 1, y = n - (n / 2) - 1;
            if (!x || !y) {
                continue;
            }
            if ((y * i) % x == 0) {
                a = (y * i) / x, b = i;
                break;
            }
        }
        if (a == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << (i & 1 ? a : -b) << " ";
            }
            cout << "\n";
        }
    }
}
