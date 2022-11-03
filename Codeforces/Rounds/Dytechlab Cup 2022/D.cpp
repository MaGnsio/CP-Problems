/**
 *    author:  MaGnsi0
 *    created: 07.10.2022 18:24:48
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> u(m), v(m), w(m);
        for (int i = 0; i < m; ++i) {
            cin >> u[i] >> v[i] >> w[i];
            u[i]--, v[i]--;
        }
        vector<vector<int64_t>> d(n, vector<int64_t>(n, OO));
        for (int i = 0; i < n; ++i) {
            d[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            d[u[i]][v[i]] = d[v[i]][u[i]] = 1;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        vector<int64_t> mine(n, OO);
        for (int i = 0; i < m; ++i) {
            mine[u[i]] = min(mine[u[i]], 1LL * w[i]);
            mine[v[i]] = min(mine[v[i]], 1LL * w[i]);
        }
        int64_t ans = OO;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = min(ans, (d[i][j] + d[j][0] + d[j][n - 1] + 2) * mine[i]);
            }
        }
        for (int i = 0; i < m; ++i) {
            ans = min(ans, (d[u[i]][0] + d[v[i]][n - 1] + 1) * w[i]);
            ans = min(ans, (d[v[i]][0] + d[u[i]][n - 1] + 1) * w[i]);
        }
        cout << ans << "\n";
    }
}
