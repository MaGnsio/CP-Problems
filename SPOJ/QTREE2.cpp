/**
 *    author:  MaGnsi0
 *    created: 08.12.2021 15:02:08
**/
#include <bits/stdc++.h>

using namespace std;

struct LCA {
    int N, L, t;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    void dfs(vector<vector<pair<int, long long>>>& adj, int v, int p, int d = 0) {
        tin[v] = ++t;
        depth[v] = d;
        up[v][0] = p;
        for (int i = 1; i <= L; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (auto& x : adj[v]) {
            int u = x.first;
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
    LCA(int n, int root, vector<vector<pair<int, long long>>>& adj) {
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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<pair<int, long long>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u - 1].push_back({v - 1, w});
            adj[v - 1].push_back({u - 1, w});
        }
        LCA A(n, 0, adj);
        vector<long long> d(n, 0);
        {
            function<void(int, int, long long)> dfs = [&](int v, int p, long long c) {
                d[v] = c;
                for (auto& x : adj[v]) {
                    int u = x.first;
                    long long w = x.second;
                    if (u != p) {
                        dfs(u, v, c + w);
                    }
                }
            };
            dfs(0, -1, 0);
        }
        string Q;
        cin >> Q;
        while (Q != "DONE") {
            if (Q == "DIST") {
                int u, v;
                cin >> u >> v;
                u--, v--;
                cout << d[u] + d[v] - 2 * d[A.lca(u, v)] << "\n";
            } else {
                int u, v, k;
                cin >> u >> v >> k;
                u--, v--;
                assert(A.depth[u] + A.depth[v] - 2 * A.depth[A.lca(u, v)] + 1 >= k);
                if (k > A.depth[u] - A.depth[A.lca(u, v)] + 1) {
                    cout << A.Kth(A.depth[u] + A.depth[v] - 2 * A.depth[A.lca(u, v)] - k + 1, v) + 1 << "\n";
                } else {
                    cout << A.Kth(k - 1, u) + 1 << "\n";
                }
            }
            cin >> Q;
        }
        cout << "\n";
    }
}
