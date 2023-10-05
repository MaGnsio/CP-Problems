/**
 *    author:  MaGnsi0
 *    created: 09.12.2021 21:45:17
**/
#include <bits/stdc++.h>

using namespace std;

struct LCA {
    int N, L, t;
    vector<int> tin, tout, depth;
    vector<vector<int>> up, citizens;
    vector<vector<vector<int>>> smallest_citizens;
    vector<int> merge(vector<int> x, vector<int> y) {
        vector<int> z;
        for (int i = 0; i < (int)x.size(); ++i) {
            z.push_back(x[i]);
        }
        for (int i = 0; i < (int)y.size(); ++i) {
            z.push_back(y[i]);
        }
        sort(z.begin(), z.end());
        z.resize(unique(z.begin(), z.end()) - z.begin());
        z.resize(min((int)z.size(), 10));
        return z;
    }
    void dfs(vector<vector<int>>& adj, int v, int p, int d = 0) {
        tin[v] = ++t;
        depth[v] = d;
        up[v][0] = p;
        smallest_citizens[v][0] = merge(citizens[v], citizens[p]);
        for (int i = 1; i <= L; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
            smallest_citizens[v][i] = merge(smallest_citizens[v][i - 1], smallest_citizens[up[v][i - 1]][i - 1]);
        }
        for (auto& u : adj[v]) {
            if (u != p) {
                dfs(adj, u, v, d + 1);
            }
        }
        tout[v] = ++t;
        return;
    }
    bool is_ancestor(int u, int v) {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    }
    vector<int> lca(int u, int v) {
        vector<int> res;
        res = merge(citizens[u], citizens[v]);
        if (is_ancestor(u, v)) {
            for (int i = L; i >= 0; --i) {
                if (!is_ancestor(up[v][i], u)) {
                    res = merge(res, smallest_citizens[v][i]);
                    v = up[v][i];
                }
            }
            return res;
        }
        if (is_ancestor(v, u)) {
            for (int i = L; i >= 0; --i) {
                if (!is_ancestor(up[u][i], v)) {
                    res = merge(res, smallest_citizens[u][i]);
                    u = up[u][i];
                }
            }
            return res;
        }
        int tv = v;
        for (int i = L; i >= 0; --i) {
            if (!is_ancestor(up[tv][i], u)) {
                res = merge(res, smallest_citizens[tv][i]);
                tv = up[tv][i];
            }
        }
        for (int i = L; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                res = merge(res, smallest_citizens[u][i]);
                u = up[u][i];
            }
        }
        u = up[u][0];
        res = merge(res, citizens[u]);
        return res;
    }
    LCA(int n, int root, vector<int>& a, vector<vector<int>>& adj) {
        N = n;
        L = 32 - __builtin_clz(N);
        t = 0;
        tin.resize(N);
        tout.resize(N);
        depth.resize(N);
        up.assign(N, vector<int>(L + 1));
        citizens.assign(N, vector<int>());
        for (int i = 0; i < (int)a.size(); ++i) {
            citizens[a[i]].push_back(i);
        }
        for (int i = 0; i < N; ++i) {
            citizens[i] = merge(citizens[i], citizens[i]);
        }
        smallest_citizens.assign(N, vector<vector<int>>(L + 1));
        dfs(adj, root, root);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    LCA A(n, 0, a, adj);
    for (int i = 0; i < q; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        vector<int> res = A.lca(u, v);
        cout << min((int)res.size(), k);
        for (int i = 0; i < min((int)res.size(), k); ++i) {
            cout << " " << res[i] + 1;
        }
        cout << "\n";
    }
}
