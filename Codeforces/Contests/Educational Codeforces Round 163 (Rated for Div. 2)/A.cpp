/**
 *    author:  MaGnsi0
 *    created: 29.05.2024 21:51:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n & 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n / 2; ++i) {
            cout << (i & 1 ? "AA" : "BB");
        }
        cout << "\n";
    }
}
