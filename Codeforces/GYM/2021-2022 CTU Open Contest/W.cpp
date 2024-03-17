/**
 *    author:  MaGnsi0
 *    created: 01.02.2024 01:03:55
**/
#include <bits/stdc++.h>

using namespace std;

struct LCA {
    int N, L, t;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    void dfs(vector<vector<int>>& adj, int v, int p, int d = 0) {
        tin[v] = ++t;
        depth[v] = d;
        up[v][0] = p;
        for (int i = 1; i <= L; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto& u : adj[v]) {
            if (u != p) {
                dfs(adj, u, v, d + 1);
            }
        }
        tout[v] = ++t;
    }
    bool is_ancestor(int u, int v) {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v)) {
            return u;
        }
        if (is_ancestor(v, u)) {
            return v;
        }
        for (int i = L; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }
    LCA(int n, int root, vector<vector<int>>& adj) {
        N = n;
        L = 32 - __builtin_clz(N);
        t = 0;
        tin.resize(N);
        tout.resize(N);
        depth.resize(N);
        up.assign(N, vector<int>(L + 1));
        dfs(adj, root, root);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> adj(n), tree(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u;
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<pair<int, int>> q;
    vector<int64_t> d(n, -1);
    d[0] = 0; q.emplace(0, 0);
    while (!q.empty()) {
        int v = q.begin() -> second;
        q.erase(q.begin());
        for (int u : adj[v]) {
            if (d[u] != -1) { continue; }
            d[u] = d[v] + 1;
            q.emplace(d[u], u);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return (d[i] < d[j]) || (d[i] == d[j] && i < j);
        });
    LCA b(n, 0, tree);
    int64_t ans = 0;
    for (int i = 1; i < n; ++i) {
        int v = I[i], u = I[i - 1];
        ans += d[v] + d[u] - 2 * d[b.lca(u, v)];
    }
    cout << ans;
}
