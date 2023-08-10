/**
 *    author:  MaGnsi0
 *    created: 26.06.2023 21:10:46
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
    int get(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    LCA D(n, 0, adj);
    vector<int> size(n), ans_down(n, n), parent(n, -1), is_centroid(n, 0);
    function<void(int, int)> dfs = [&](int v, int p) {
        size[v] = 1;
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            dfs(u, v);
            size[v] += size[u];
        }
    };
    function<int(int, int, int)> get_centroid = [&](int v, int p, int s) {
        for (int u : adj[v]) {
            if (u == p || is_centroid[u]) { continue; }
            if (2 * size[u] > s) { return get_centroid(u, v, s); }
        }
        return v;
    };
    function<void(int, int)> solve = [&](int v, int p) {
        dfs(v, -1);
        v = get_centroid(v, -1, size[v]);
        is_centroid[v] = 1, parent[v] = p;
        for (int u : adj[v]) {
            if (is_centroid[u]) { continue; }
            solve(u, v);
        }
    };
    function<void(int)> update = [&](int v) {
        int u = v;
        while (u != -1) {
            ans_down[u] = min(ans_down[u], D.get(u, v));
            u = parent[u];
        }
    };
    function<int(int)> get = [&](int v) {
        int ans = ans_down[v], u = v;
        while (u != -1) {
            ans = min(ans, ans_down[u] + D.get(u, v));
            u = parent[u];
        }
        return ans;
    };
    solve(0, -1); update(0);
    for (int i = 0; i < m; ++i) {
        int t, u;
        cin >> t >> u;
        if (t == 1) {
            update(u - 1);
        } else {
            cout << get(u - 1) << "\n";
        }
    }
}
