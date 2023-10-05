/**
 *    author:  MaGnsi0
 *    created: 02.08.2023 17:46:18
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15;

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
    vector<bool> used(m, false), visited(n, false);
    vector<int> U(m), V(m), W(m);
    vector<vector<tuple<int, int64_t, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        cin >> U[i] >> V[i] >> W[i];
        U[i]--, V[i]--;
        adj[U[i]].emplace_back(V[i], W[i], i);
        adj[V[i]].emplace_back(U[i], W[i], i);
    }
    vector<int64_t> d(n);
    vector<vector<int>> tree(n);
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        for (auto [u, w, j] : adj[v]) {
            if (visited[u]) { continue; }
            used[j] = true;
            d[u] = d[v] + w;
            tree[u].emplace_back(v);
            tree[v].emplace_back(u);
            dfs(u);
        }
    };
    dfs(0);
    LCA L(n, 0, tree);
    vector<vector<int64_t>> c;
    function<vector<int64_t>(int)> dijkstra = [&](int source) {
        vector<int64_t> d(n, OO);
        set<pair<int64_t, int>> s;
        d[source] = 0;
        s.emplace(0, source);
        while (!s.empty()) {
            int v = s.begin() -> second;
            int64_t d_v = s.begin() -> first;
            s.erase(s.begin());
            if (d_v != d[v]) { continue; }
            for (auto [u, w, _] : adj[v]) {
                if (d[v] + w < d[u]) {
                    d[u] = d[v] + w;
                    s.emplace(d[u], u);
                }
            }
        }
        return d;
    };
    for (int i = 0; i < m; ++i) {
        if (used[i] == false) {
            c.emplace_back(dijkstra(U[i]));
        }
    }
    int k = (int)c.size(), Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int64_t ans = d[u] + d[v] - 2 * d[L.lca(u, v)];
        for (int i = 0; i < k; ++i) {
            ans = min(ans, c[i][u] + c[i][v]);
        }
        cout << ans << "\n";
    }
}
