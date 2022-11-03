/**
 *    author:  MaGnsi0
 *    created: 11.12.2021 03:28:07
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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        map<pair<int, int>, int> id;
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            if (u > v) {
                swap(u, v);
            }
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
            id[{u, v}] = i;
        }
        vector<vector<int>> f(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            f[x - 1].push_back(i);
        }
        vector<int> sum(n, 0);
        LCA A(n, 0, adj);
        for (int i = 0; i < n; ++i) {
            if (f[i].size() <= 1) {
                continue;
            }
            int l = f[i][0];
            for (int j = 1; j < (int)f[i].size(); ++j) {
                l = A.lca(l, f[i][j]);
            }
            sum[l] -= (int)f[i].size();
            for (int j = 0; j < (int)f[i].size(); ++j) {
                sum[f[i][j]]++;
            }
        }
        int res = 0;
        function<void(int, int)> dfs = [&](int v, int p) {
            for (auto& u : adj[v]) {
                if (u != p) {
                    dfs(u, v);
                    sum[v] += sum[u];
                }
            }
            if (p != -1 && sum[v] == 0) {
                res++;
            }
            return;
        };
        dfs(0, -1);
        cout << "Case #" << t << ": " << res << "\n";
    }
}
