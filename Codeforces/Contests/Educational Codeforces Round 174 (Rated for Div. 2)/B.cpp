/**
 *    author:  MaGnsi0
 *    created: 18.02.2025 16:49:40
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j]; a[i][j]--;
            }
        }
        vector<int> f(n * m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int c = a[i][j];
                f[c] = max(f[c], 1);
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || ni >= n) { continue; }
                    if (nj < 0 || nj >= m) { continue; }
                    if (a[ni][nj] == c) { f[c] = max(f[c], 2); }
                }
            }
        }
        sort(f.begin(), f.end());
        int ans = 0;
        for (int i = 0; i < n * m - 1; ++i) {
            ans += f[i];
        }
        cout << ans << "\n";
    }
}
