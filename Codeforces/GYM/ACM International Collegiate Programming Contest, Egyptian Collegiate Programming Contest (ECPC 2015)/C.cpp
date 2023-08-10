#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, length;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) {
            return;
        }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += length[Py];
    }
};

struct LCA {
    int N, L, t;
    vector<int> tin, tout, depth;
    vector<vector<int>> up, dp;
    void dfs(vector<vector<pair<int, int>>>& adj, int v, int p, int d = 0, int val = 0) {
        tin[v] = ++t;
        depth[v] = d;
        up[v][0] = p;
        dp[v][0] = val;
        for (int i = 1; i <= L; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
            dp[v][i] = max(dp[v][i - 1], dp[up[v][i - 1]][i - 1]);
        }
        for (auto [u, w] : adj[v]) {
            if (u != p) {
                dfs(adj, u, v, d + 1, w);
            }
        }
        tout[v] = ++t;
    }
    bool is_ancestor(int u, int v) {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    }
    int get(int u, int v) {
        if (is_ancestor(u, v)) {
            int d = depth[v] - depth[u], ans = 0;
            for (int i = L; i >= 0; --i) {
                if ((d >> i) & 1) {
                    ans = max(ans, dp[v][i]);
                    v = up[v][i];
                }
            }
            return ans;
        }
        if (is_ancestor(v, u)) {
            int d = depth[u] - depth[v], ans = 0;
            for (int i = L; i >= 0; --i) {
                if ((d >> i) & 1) {
                    ans = max(ans, dp[u][i]);
                    u = up[u][i];
                }
            }
            return ans;
        }
        int old_u = u, old_v = v;
        for (int i = L; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return max(get(old_u, up[u][0]), get(old_v, up[u][0]));
    }
    LCA(int n, int root, vector<vector<pair<int, int>>>& adj) {
        N = n;
        L = 32 - __builtin_clz(N);
        t = 0;
        tin.resize(N);
        tout.resize(N);
        depth.resize(N);
        up.assign(N, vector<int>(L + 1));
        dp.assign(N, vector<int>(L + 1));
        dfs(adj, root, root);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);
        union_find dsu(n);
        vector<int> U, V, T;
        for (int i = 1; i <= m; ++i) {
            int t; cin >> t;
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (t == 1) {
                if (dsu.find(u) == dsu.find(v)) { continue; }
                dsu.unite(u, v);
                adj[u].emplace_back(v, i);
                adj[v].emplace_back(u, i);
            } else {
                U.push_back(u);
                V.push_back(v);
                T.push_back(i);
            }
        }
        vector<int> p;
        for (int i = 0; i < n; ++i) {
            p.push_back(dsu.find(i));
        }
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin());
        for (int i = 1; i < (int)p.size(); ++i) {
            dsu.unite(p[i], p[i - 1]);
            adj[p[i]].emplace_back(p[i - 1], m + 1);
            adj[p[i - 1]].emplace_back(p[i], m + 1);
        }
        LCA L(n, 0, adj);
        for (int i = 0; i < (int)U.size(); ++i) {
            int ans = L.get(U[i], V[i]);
            cout << (ans > T[i] ? -1 : ans) << "\n";
        }
    }
}
