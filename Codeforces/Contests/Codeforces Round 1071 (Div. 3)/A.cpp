/**
 *    author:  MaGnsi0
 *    created: 23.12.2025 16:45:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        int x; cin >> x;
        int n = 1;
        while (true) {
            int c = 1;
            for (int i = 1; i < n; ++i) {
                c += (n - i) % x == 0;
            }
            if (c > k) { break; }
            n++;
        }
        cout << n << "\n";
    }
}
