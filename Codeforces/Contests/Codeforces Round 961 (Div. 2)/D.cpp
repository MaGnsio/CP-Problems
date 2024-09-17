/**
 *    author:  MaGnsi0
 *    created: 17.09.2024 04:03:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int c; cin >> c;
        int k; cin >> k;
        int m = 1 << c;
        string s; cin >> s;
        vector F(n, vector<int>(c));
        for (int i = 0; i < n; ++i) {
            F[i][s[i] - 'A']++;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < c; ++j) {
                F[i][j] += F[i - 1][j];
            }
        }
        vector<bool> bad(m);
        bad[1 << (s[n - 1] - 'A')] = true;
        for (int i = k - 1; i < n; ++i) {
            int mask = 0;
            for (int j = 0; j < c; ++j) {
                if (F[i][j] - (i == k - 1 ? 0 : F[i - k][j])) {
                    mask |= 1 << j;
                }
            }
            bad[mask] = true;
        }
        for (int mask = 0; mask < m; ++mask) {
            for (int j = 0; j < c; ++j) {
                bad[mask | (1 << j)] = bad[mask | (1 << j)] || bad[mask];
            }
        }
        int ans = c;
        for (int mask = 0; mask < m; ++mask) {
            if (!bad[mask]) {
                ans = min(ans, c - __builtin_popcount(mask));
            }
        }
        cout << ans << "\n";
    }
}
