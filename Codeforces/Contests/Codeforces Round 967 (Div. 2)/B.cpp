/**
 *    author:  MaGnsi0
 *    created: 20.08.2024 17:49:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << -1 << "\n";
        } else {
            for (int i = 1; i <= n / 2; ++i) {
                cout << i << " ";
            }
            for (int i = n; i > n / 2; --i) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}
