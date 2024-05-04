/**
 *    author:  MaGnsi0
 *    created: 22.04.2024 10:25:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        if (n == 1) {
            cout << k << "\n";
            continue;
        }
        int p = 0;
        while ((1LL << p) - 1 <= k) { p++; } p--;
        cout << (1LL << p) - 1 << " " << k - (1LL << p) + 1;
        for (int i = 2; i < n; ++i) { cout << " 0"; }
        cout << "\n";
    }
}
