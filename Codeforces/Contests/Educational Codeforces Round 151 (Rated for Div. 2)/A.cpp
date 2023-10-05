/**
 *    author:  MaGnsi0
 *    created: 29.06.2023 17:36:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, x;
        cin >> n >> k >> x;
        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
            cout << "\n";
        } else if (k >= 2 && n % 2 == 0) {
                cout << "YES\n";
                cout << n / 2 << "\n";
                for (int i = 0; i < n / 2; ++i) {
                    cout << 2 << " ";
                }
                cout << "\n";
        } else if (k >= 3 && n > 1) {
            cout << "YES\n";
            cout << (n - 3) / 2 + 1 << "\n";
            for (int i = 0; i < (n - 3) / 2; ++i) {
                cout << 2 << " ";
            }
            cout << " 3\n";
        } else {
            cout << "NO\n";
        }
    }
}
