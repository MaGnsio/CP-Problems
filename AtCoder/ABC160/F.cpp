/**
 *    author:  MaGnsi0
 *    created: 08.09.2022 21:02:20
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 1e9 + 7;

vector<int64_t> F(N, 1);

int64_t power(int64_t x, int64_t y) {
    int64_t res = 1;
    while (y) {
        if (y & 1) { res = res * x % MOD; }
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

int64_t mod_inverse(int64_t x) {
    return power(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int64_t i = 1; i < N; ++i) {
        F[i] = i * F[i - 1];
        F[i] %= MOD;
    }
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int64_t> sz(n), dp(n);
    function<int64_t(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        for (auto& u : adj[v]) {
            if (u != p) {
                sz[v] += dfs(u, v);
            }
        }
        return sz[v];
    };
    function<int64_t(int, int)> solve = [&](int v, int p) {
        dp[v] = F[sz[v] - 1];
        for (auto& u : adj[v]) {
            if (u != p) {
                dp[v] = dp[v] * mod_inverse(F[sz[u]]) % MOD * solve(u, v) % MOD;
            }
        }
        return dp[v];
    };
    dfs(0, -1);
    solve(0, -1);
    vector<int64_t> ans(n);
    function<void(int, int)> reroot = [&](int v, int p) {
        ans[v] = dp[v];
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            int old_size_v = sz[v];
            int old_size_u = sz[u];
            int64_t old_dp_v = dp[v];
            int64_t old_dp_u = dp[u];
            dp[v] *= mod_inverse(F[sz[v] - 1]);
            dp[v] %= MOD;
            dp[v] *= F[sz[u]];
            dp[v] %= MOD;
            dp[v] *= F[sz[v] - sz[u] - 1];
            dp[v] %= MOD;
            dp[v] *= mod_inverse(dp[u]);
            dp[v] %= MOD;
            dp[u] *= mod_inverse(F[sz[u] - 1]);
            dp[u] %= MOD;
            dp[u] *= F[sz[v] - 1];
            dp[u] %= MOD;
            dp[u] *= mod_inverse(F[sz[v] - sz[u]]);
            dp[u] %= MOD;
            dp[u] *= dp[v];
            dp[u] %= MOD;
            sz[v] = old_size_v - old_size_u;
            sz[u] = old_size_v;
            reroot(u, v);
            sz[v] = old_size_v;
            sz[u] = old_size_u;
            dp[v] = old_dp_v;
            dp[u] = old_dp_u;
        }
    };
    reroot(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
}
