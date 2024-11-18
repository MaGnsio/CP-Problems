/**
 *    author:  MaGnsi0
 *    created: 18.11.2024 22:48:31
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t CHUNK_SIZE = 100, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m; cin >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
    }
    int64_t ans = 0, k = 0, chunk = 0;
    vector<int64_t> dp(n, -1);
    map<int, int64_t> updates;
    vector<vector<int64_t>> b(n);
    function<void(int)> calc_contrib = [&](int v) {
        if (!b[v].empty()) { return; }
        b[v] = vector<int64_t>(n, 0); b[v][v] = 1;
        for (int u : adj[v]) {
            calc_contrib(u);
            for (int i = 0; i < n; ++i) {
                b[v][i] += b[u][i]; b[v][i] %= MOD;
            }
        }
    };
    function<int64_t(int)> solve = [&](int v) {
        if (dp[v] != -1) { return dp[v]; }
        dp[v] = a[v];
        for (int u : adj[v]) {
            dp[v] += solve(u); dp[v] %= MOD;
        }
        return dp[v];
    };
    function<void()> recalculate = [&]() {
        for (auto [j, x] : updates) {
            a[j] = x;
        }
        dp = vector<int64_t>(n, -1);
        updates.clear();
    };
    function<int64_t(int)> F = [&](int v) {
        int64_t res = solve(v);
        for (auto [j, x] : updates) {
            res -= b[v][j] * a[j];
            res += MOD; res %= MOD;
            res += b[v][j] * x;
            res %= MOD;
        }
        return res;
    };
    for (int i = 0; i < n; ++i) {
        calc_contrib(i);
    }
    int Q; cin >> Q;
    while (Q--) {
        char t; cin >> t;
        if (t == 'U') {
            int j; cin >> j; j--;
            int x; cin >> x;
            updates[j] = x;
            if (++chunk == CHUNK_SIZE) {
                recalculate();
                chunk = 0;
            }
        } else {
            int j; cin >> j; j--;
            ans += (++k) * F(j) % MOD;
            ans %= MOD;
        }
    }
    cout << ans;
}
