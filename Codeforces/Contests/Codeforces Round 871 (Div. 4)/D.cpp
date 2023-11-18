/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 16:37:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        function<bool(int)> F = [&](int x) {
            if (x == m) { return true; }
            if (x % 3) { return false; }
            return F(x / 3) || F(2 * x / 3);
        };
        cout << (F(n) ? "YES" : "NO") << "\n";
    }
}
