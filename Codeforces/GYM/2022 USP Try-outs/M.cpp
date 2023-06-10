/**
 *    author:  MaGnsi0
 *    created: 06.06.2023 04:38:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].emplace_back(v - 1, i);
        adj[v - 1].emplace_back(u - 1, i);
    }
    vector<set<int>> bcc;
    vector<int> minh(n), h(n);
    vector<bool> visited(n), collected(m);
    function<void(int, int)> collect = [&](int v, int p) {
        for (auto [u, e] : adj[v]) {
            if (!collected[e]) {
                bcc.back().insert(u);
                bcc.back().insert(v);
                collected[e] = true;
                if (u != p) {
                    collect(u, p);
                }
            }
        }
    };
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        minh[v] = h[v];
        for (auto [u, e] : adj[v]) {
            if (!visited[u]) {
                h[u] = h[v] + 1;
                dfs(u);
                minh[v] = min(minh[v], minh[u]);
                if (minh[u] == h[v] && !collected[e]) {
                    bcc.emplace_back();
                    collect(u, v);
                }
            } else {
                minh[v] = min(minh[v], h[u]);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (adj[i].empty()) {
                bcc.push_back({i});
            } else {
                dfs(i);
            }
        }
    }
    int k = (int)bcc.size();
    vector<int> color(n, 0);
    visited = vector<bool>(n, false);
    function<void(int)> reset = [&](int j) {
        for (int v : bcc[j]) {
            color[v] = 0;
            visited[v] = false;
        }
    };
    function<bool(int, int, int)> bipartite = [&](int v, int g, int c) {
        visited[v] = true, color[v] = c;
        for (auto [u, e] : adj[v]) {
            if (bcc[g].count(u) == 0) { continue; }
            if (visited[u] && color[u] == color[v]) {
                return false;
            }
            if (!visited[u] && !bipartite(u, g, c ^ 1)) {
                return false;
            }
        }
        return true;
    };
    vector<bool> banned(m, false);
    function<void(int, int)> ban = [&](int v, int g) {
        visited[v] = true;
        for (auto [u, e] : adj[v]) {
            if (bcc[g].count(u) == 0) { continue; }
            banned[e] = true;
            if (!visited[u]) { ban(u, g); }
        }
    };
    for (int i = 0; i < k; ++i) {
        int v = *bcc[i].begin();
        if (!bipartite(v, i, 0)) {
            reset(i);
            ban(v, i);
        }
        reset(i);
    }
    int64_t x = 0, y = 0;
    int64_t ans_odd = 0, ans_even = 0;
    function<void(int, int)> solve = [&](int v, int c) {
        visited[v] = true;
        color[v] = c;
        x += c == 0;
        y += c == 1;
        for (auto [u, e] : adj[v]) {
            if (banned[e]) { continue; }
            if (visited[u]) {
                assert(color[v] != color[u]);
                continue;
            }
            solve(u, c ^ 1);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            solve(i, 0);
            ans_even += x * y;
            ans_odd += x * (x - 1) / 2;
            ans_odd += y * (y - 1) / 2;
            x = 0, y = 0;
        }
    }
    cout << ans_odd << " " << ans_even;
}
