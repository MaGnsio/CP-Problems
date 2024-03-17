/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 14:27:08
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        int w; cin >> w;
        adj[u].emplace_back(v, w);
    }
    vector<vector<int64_t>> D(n);
    function<vector<int64_t>(int)> dijkstra = [&](int source) {
        vector<int64_t> d(n, OO);
        set<pair<int64_t, int>> s;
        d[source] = 0;
        s.emplace(0, source);
        while (!s.empty()) {
            auto [dv, v] = *s.begin();
            s.erase(s.begin());
            if (dv != d[v]) { continue; }
            for (auto [u, w] : adj[v]) {
                if (d[v] + w < d[u]) {
                    d[u] = d[v] + w;
                    s.emplace(d[u], u);
                }
            }
        }
        return d;
    };
    for (int i = 0; i < n; ++i) {
        D[i] = dijkstra(i);
    }
    vector<vector<int64_t>> dp(1 << n, vector<int64_t>(n, -OO));
    function<int64_t(int, int)> solve = [&](int mask, int v) {
        if (mask == ((1 << n) - 1)) { return int64_t(0); }
        int64_t& res = dp[mask][v];
        if (res != -OO) { return res; }
        res = OO;
        for (int u = 0; u < n; ++u) {
            if (mask >> u & 1) { continue; }
            if (D[v][u] == OO) { continue; }
            int64_t add = solve(mask | (1 << u), u);
            if (add == OO) { continue; }
            res = min(res, add + D[v][u]);
        }
        return res;
    };
    int64_t ans = OO;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, solve(1 << i, i));
    }
    if (ans == OO) {
        cout << "No";
    } else {
        cout << ans;
    }
}
