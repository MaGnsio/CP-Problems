/**
 *    author:  MaGnsi0
 *    created: 10.07.2022 16:32:33
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
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    LCA T(n, 0, adj);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[j];
            a[j]--;
        }
        function<int(int, int)> D = [&](int u, int v) {
            int w = T.lca(u, v);
            return (T.depth[u] + T.depth[v] - 2 * T.depth[w]);
        };
        int u = a[0];
        for (int j = 0; j < k; ++j) {
            if (T.depth[a[j]] > T.depth[u]) {
                u = a[j];
            }
        }
        int v = a[0], maxD = 0;
        for (int j = 0; j < k; ++j) {
            if (D(u, a[j]) > maxD) {
                v = a[j];
                maxD = D(u, a[j]);
            }
        }
        bool ok = true;
        for (int j = 0; j < k; ++j) {
            ok &= (D(u, a[j]) + D(a[j], v) == maxD);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
