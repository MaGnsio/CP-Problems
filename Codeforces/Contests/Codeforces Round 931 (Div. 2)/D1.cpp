/**
 *    author:  MaGnsi0
 *    created: 26.11.2024 20:22:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        vector<int64_t> ans(1, n);
        int64_t base = 0, MSB = 0;
        for (int b = 61; b >= 0; --b) {
            if (!(n >> b & 1) && (m >> b & 1)) {
                base |= (1LL << b);
            }
            if ((n >> b & 1) && !(m >> b & 1)) {
                MSB = max(MSB, int64_t(b));
            }
        }
        if (base) {
            if (m >> MSB & 1) {
                cout << -1 << "\n";
                continue;
            }
            base |= (1LL << MSB);
            if (base >= n) {
                cout << -1 << "\n";
                continue;
            }
            n ^= base; ans.push_back(n);
        }
        for (int b = 61; b >= 0; --b) {
            if (n == m) { break; }
            if (n < m) {
                cout << -1 << "\n";
                break;
            }
            if (!(n >> b & 1) || (m >> b & 1)) { continue; }
            n = n ^ (1LL << b); ans.push_back(n);
        }
        if (ans.back() == m) {
            cout << (int)ans.size() - 1 << "\n";
            for (int64_t x : ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}
