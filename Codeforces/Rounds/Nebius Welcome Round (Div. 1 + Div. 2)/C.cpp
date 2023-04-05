/**
 *    author:  MaGnsi0
 *    created: 12.03.2023 16:54:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, x, p;
        cin >> n >> x >> p;
        int64_t y = (n - x) % n;
        bool ok = false;
        for (int64_t i = 1; i <= min(2 * (n + 1), p); ++i) {
            ok |= ((i * (i + 1) / 2) % n) == y;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
