/**
 *    author:  MaGnsi0
 *    created: 20.08.2022 01:09:44
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> u(n - 1), v(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> u[i] >> v[i];
            u[i]--, v[i]--;
        }
        int m;
        cin >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }
        vector<int64_t> b(n), p(n);
        {
            function<int64_t(int, int)> dfs = [&](int v, int p_) {
                b[v] = 1;
                p[v] = p_;
                for (auto& u : adj[v]) {
                    if (u != p_) {
                        b[v] += dfs(u, v);
                    }
                }
                return b[v];
            };
            dfs(0, -1);
        }
        vector<int64_t> c(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            if (p[v[i]] == u[i]) {
                c[i] = b[v[i]] * (n - b[v[i]]);
            } else {
                c[i] = b[u[i]] * (n - b[u[i]]);
            }
        }
        sort(c.begin(), c.end());
        vector<int64_t> d(n - 1, 1);
        for (int i = (m >= n - 1 ? 0 : n - m - 1), j = 0; i < n - 1; ++i, ++j) {
            d[i] *= a[j];
            d[i] %= MOD;
            if (i == n - 2) {
                for (j = j + 1; j < m; ++j) {
                    d[i] *= a[j];
                    d[i] %= MOD;
                }
            }
        }
        int64_t ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans += (c[i] % MOD * d[i]) % MOD;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
