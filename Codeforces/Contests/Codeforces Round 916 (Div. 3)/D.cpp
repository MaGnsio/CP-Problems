/**
 *    author:  MaGnsi0
 *    created: 21.12.2023 15:29:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> I(n), J(n), K(n);
        vector<int64_t> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return a[i] > a[j];
            });
        iota(J.begin(), J.end(), 0);
        sort(J.begin(), J.end(), [&](int i, int j) {
                return b[i] > b[j];
            });
        iota(K.begin(), K.end(), 0);
        sort(K.begin(), K.end(), [&](int i, int j) {
                return c[i] > c[j];
            });
        int64_t ans = 0;
        for (int i = 0; i < min(n, 10); ++i) {
            for (int j = 0; j < min(n, 10); ++j) {
                for (int k = 0; k < min(n, 10); ++k) {
                    int x = I[i], y = J[j], z = K[k];
                    if (x == y || x == z || y == z) { continue; }
                    ans = max(ans, a[x] + b[y] + c[z]);
                }
            }
        }
        cout << ans << "\n";
    }
}
