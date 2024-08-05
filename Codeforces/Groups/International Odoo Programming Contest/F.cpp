/**
 *    author:  MaGnsi0
 *    created: 31.03.2024 02:36:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t MOD; cin >> MOD;
    int Q; cin >> Q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i] %= MOD;
    }
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; ++v) {
        int u; cin >> u; u--;
        adj[u].emplace_back(v);
    }
    vector<vector<pair<int, int64_t>>> b(n);
    for (int t = 1; t <= Q; ++t) {
        int v; cin >> v; v--;
        int64_t x; cin >> x; x %= MOD;
        b[v].emplace_back(t, x);
    }
    int m = Q + 1; 
    vector<int64_t> T(4 * m, 1);
    function<void(int, int, int, int, int64_t)> update = [&](int j, int low, int high, int p, int64_t x) {
        if (low == high) { T[j] = x; return; }
        int mid = (low + high) / 2;
        if (p <= mid) {
            update(2 * j + 1, low, mid, p, x);
        } else {
            update(2 * j + 2, mid + 1, high, p, x);
        }
        T[j] = T[2 * j + 1] * T[2 * j + 2] % MOD;
    };
    function<int(int, int, int, int64_t)> query = [&](int j, int low, int high, int64_t p) {
        if (p * T[j] % MOD) { return -1; }
        if (low == high) { return low; }
        int mid = (low + high) / 2;
        int64_t np = p * T[2 * j + 1] % MOD;
        if (np == 0) {
            return query(2 * j + 1, low, mid, p);
        }
        return query(2 * j + 2, mid + 1, high, np);
    };
    vector<int> ans(n);
    function<void(int)> dfs = [&](int v) {
        for (auto [t, x] : b[v]) {
            update(0, 0, m - 1, t, x);
        }
        update(0, 0, m - 1, 0, a[v]);
        ans[v] = query(0, 0, m - 1, 1);
        for (int u : adj[v]) {
            dfs(u);
        }
        for (auto [t, _] : b[v]) {
            update(0, 0, m - 1, t, 1);
        }
    };
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
