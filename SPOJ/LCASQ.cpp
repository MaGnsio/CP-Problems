/**
 *    author:  MaGnsi0
 *    created: 08.12.2021 14:55:52
**/
#include <bits/stdc++.h>

using namespace std;

struct LCA {
    int N, L, t;
    vector<int> tin, tout;
    vector<vector<int>> up;
    void dfs(vector<vector<int>>& adj, int v, int p) {
        tin[v] = ++t;
        up[v][0] = p;
        for (int i = 1; i <= L; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto& u : adj[v]) {
            if (u != p) {
                dfs(adj, u, v);
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
        up.assign(N, vector<int>(L + 1));
        dfs(adj, root, root);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; ++u) {
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int v;
            cin >> v;
            adj[u].push_back(v);
        }
    }
    LCA A(n, 0, adj);
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << A.lca(x, y) << "\n";
    }
}
