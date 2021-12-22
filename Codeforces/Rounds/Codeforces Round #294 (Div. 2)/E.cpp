/**
 *    author:  MaGnsi0
 *    created: 08.12.2021 16:39:45
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
    int Kth_ancestor(int k, int v) {
        for (int i = 0; (k >> i) != 0; ++i) {
            if ((k >> i) & 1) {
                v = up[v][i];
            }
        }
        return v;
    }
    int raise(int u, int x) {
        for (int i = L; i >= 0; --i) {
            if (!is_ancestor(up[u][i], x)) {
                u = up[u][i];
            }
        }
        return u;
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
    vector<int> sz(n, 0);
    {
        function<int(int, int)> dfs = [&](int v, int p) {
            sz[v] = 1;
            for (auto& u : adj[v]) {
                if (u != p) {
                    sz[v] += dfs(u, v);
                }
            }
            return sz[v];
        };
        dfs(0, -1);
    }
    LCA A(n, 0, adj);
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int dis = A.depth[u] + A.depth[v] - 2 * A.depth[A.lca(u, v)];
        if (dis & 1) {
            cout << 0 << "\n";
        } else if (u == v) {
            cout << n << "\n";
        } else {
            int l = A.lca(u, v);
            if (A.depth[u] - A.depth[l] == A.depth[v] - A.depth[l]) {
                u = A.raise(u, l);
                v = A.raise(v, l);
                cout << n - sz[u] - sz[v] << "\n"; 
            } else if (A.depth[u] - A.depth[A.lca(u, v)] > dis / 2) {
                l = A.Kth_ancestor(dis / 2, u);
                u = A.raise(u, l);
                cout << sz[l] - sz[u] << "\n";
            } else {
                l = A.Kth_ancestor(dis / 2, v);
                v = A.raise(v, l);
                cout << sz[l] - sz[v] << "\n";
            }
        }
    }
}
