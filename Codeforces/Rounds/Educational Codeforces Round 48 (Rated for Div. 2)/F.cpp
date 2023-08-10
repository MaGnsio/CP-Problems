/**
 *    author:  MaGnsi0
 *    created: 01.08.2023 14:32:33
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int64_t>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }
    int time = 0;
    vector<int> in(n), out(n), s(n, 1), p(n, -1);
    vector<int64_t> d(n);
    function<void(int)> dfs = [&](int v) {
        in[v] = time++;
        for (auto [u, w] : adj[v]) {
            if (u == p[v]) { continue; }
            p[u] = v;
            d[u] = d[v] + w;
            dfs(u);
            s[v] += s[u];
        }
        out[v] = time++;
    };
    function<bool(int, int)> is_ancestor = [&](int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    };
    dfs(0);
    int64_t ans = d[n - 1], dif = OO, mn = -OO;
    function<void(int)> dfs_ = [&](int v) {
        dif = min(dif, max(d[v] - mn, int64_t(0)));
        if (v && p[p[v]] != -1) {
            dif = min(dif, max(d[v] - d[p[p[v]]], int64_t(0)));
        }
        for (auto [u, w] : adj[v]) {
            if (u == p[v]) { continue; }
            if (is_ancestor(u, n - 1)) { continue; }
            dif = min(dif, max(d[v] - mn - w, int64_t(0)));
            mn = max(mn, d[v] + w);
            if (v) {
                dif = min(dif, max(d[v] - d[p[v]] - w, int64_t(0)));
            }
        }
        for (auto [u, _] : adj[v]) {
            if (u == p[v]) { continue; }
            if (is_ancestor(u, n - 1)) {
                dfs_(u);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!is_ancestor(i, n - 1) && s[i] > 1) {
            dif = 0;
        }
    }
    if (dif > 0) {
        dfs_(0);
    }
    for (int i = 0; i < m; ++i) {
        int64_t x; cin >> x;
        cout << min(ans, ans - dif + x) << "\n";
    }
}
