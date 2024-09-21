/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 19:57:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t k; cin >> k;
        int64_t ans = n * (n + 1) / 2;
        n = n - k;
        ans -= n * (n + 1) / 2;
        ans %= 2;
        cout << (ans == 0 ? "YES" : "NO") << "\n";
    }
}
