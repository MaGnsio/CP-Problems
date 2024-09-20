/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 01:13:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int64_t n; cin >> n;
        int64_t k; cin >> k;
        int64_t mint = INT64_MAX;
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x;
            mint = min((1 + 2 * max(n - 2, int64_t(0))) * x, mint);
        }
        cout << "Case #" << t << ": " << (mint <= k ? "YES" : "NO") << "\n";
    }
}
