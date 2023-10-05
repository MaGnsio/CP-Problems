/**
 *    author:  MaGnsi0
 *    created: 18.06.2023 00:26:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<vector<pair<int, int64_t>>>> adj(2, vector<vector<pair<int, int64_t>>>(n));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[0][u - 1].emplace_back(v - 1, w);
        adj[1][v - 1].emplace_back(u - 1, w);
    }
    vector<int> visited(n, 0), top_sort;
    function<void(int)> dfs = [&](int v) {
        visited[v] = 1;
        for (auto [u, w] : adj[0][v]) {
            if (visited[u] != 1) {
                dfs(u);
            }
        }
        top_sort.push_back(v);
    };
    for (int i = 0; i < n; ++i) {
        if (visited[i] != 1) {
            dfs(i);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    int cc = 0;
    vector<int64_t> d(n), g(n), c(n);
    function<void(int)> solve = [&](int v) {
        visited[v] = 2;
        for (auto [u, w] : adj[1][v]) {
            if (visited[u] != 2) {
                d[u] = d[v] + w, c[u] = c[v];
                solve(u);
            } else if (c[u] == c[v]) {
                g[c[u]] = __gcd(g[c[u]], abs(d[v] + w - d[u]));
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        int j = top_sort[i];
        if (visited[j] != 2) {
            d[j] = 0, c[j] = cc++;
            solve(j);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int64_t v, s, t;
        cin >> v >> s >> t;
        int64_t gg = __gcd(g[c[v - 1]], t);
        cout << (s % gg == 0 ? "YES" : "NO") << "\n";
    }
}
