/**
 *    author:  MaGnsi0
 *    created: 09.02.2025 16:48:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        vector a(n, vector<int64_t>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector<int64_t> I(n), S(n);
        for (int i = 0; i < n; ++i) {
            I[i] = i; S[i] = 0;
            for (int j = 0; j < m; ++j) {
                S[i] += a[i][j];
            }
        }
        sort(I.begin(), I.end(), [&](int i, int j) {
            return S[i] > S[j];
        });
        int64_t ans = 0, x = n * m;
        for (int i_ = 0; i_ < n; ++i_) {
            int i = I[i_];
            for (int j = 0; j < m; ++j) {
                ans += x * a[i][j]; x--;
            }
        }
        cout << ans << "\n";
    }
}
