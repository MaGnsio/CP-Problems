/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 16:55:56
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
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        int64_t ans = 0;
        vector<int64_t> a(n), b(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            a[v] = 0, b[v] = 1;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
                a[v] += a[u] + b[u];
                b[v] += b[u];
            }
        };
        function<void(int, int)> solve = [&](int v, int p) {
            ans += a[v];
            for (int u : adj[v]) {
                if (u == p) { continue; }
                int64_t av = a[v], bv = b[v];
                int64_t au = a[u], bu = b[u];
                a[v] = av - au - bu, b[v] = bv - bu;
                a[u] = au + a[v] + b[v], b[u] = bv;
                solve(u, v);
                a[v] = av, b[v] = bv;
                a[u] = au, b[u] = bu;
            }
        };
        dfs(0, -1);
        solve(0, -1);
        cout << fixed << setprecision(8) << 1.0 * ans / n << "\n";
    }
}
