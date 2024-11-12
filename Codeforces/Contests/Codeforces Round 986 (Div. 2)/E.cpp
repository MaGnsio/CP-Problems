/**
 *    author:  MaGnsi0
 *    created: 12.11.2024 19:39:11
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD; p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int64_t> x(n), ans(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            x[v] = n;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
                x[v] = min(x[v], x[u] + 1);
            }
            if (x[v] == n) { x[v] = 0; }
        };
        function<void(int, int)> solve = [&](int v, int p) {
            ans[v] = p == -1 ? 1 : x[v] * power(x[v] + 1, MOD - 2) % MOD * ans[p] % MOD;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                solve(u, v);
            }
        };
        dfs(0, -1); solve(0, -1);
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
