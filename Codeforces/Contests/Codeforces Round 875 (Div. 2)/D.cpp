/**
 *    author:  MaGnsi0
 *    created: 28.05.2023 18:42:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<vector<int64_t>> c(n + 1);
        for (int i = 0; i < n; ++i) {
            c[a[i]].push_back(b[i]);
        }
        int64_t ans = 0;
        for (int j = 1; j * j <= 2 * n; ++j) {
            vector<int64_t> f(n + 1), p(n + 1);
            for (int64_t x : c[j]) { f[x]++; }
            for (int i = 0; i < n; ++i) {
                if (a[i] < j) { continue; }
                int x = j * a[i] - b[i];
                if (0 <= x && x <= n) {
                    if (a[i] == j && b[i] < x) { continue; }
                    if (a[i] == j && b[i] == x) {
                        ans += f[x] - (++p[x]);
                    } else {
                        ans += f[x];
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
