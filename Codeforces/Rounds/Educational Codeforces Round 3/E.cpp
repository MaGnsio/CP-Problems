/**
 *    author:  MaGnsi0
 *    created: 15.04.2022 23:11:35
**/
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
    vector<vector<int>> up, maxe;
    void dfs(vector<vector<pair<int, int>>>& adj, int v, int p, int _w = 0, int d = 0) {
        tin[v] = ++t;
        depth[v] = d;
        up[v][0] = p;
        maxe[v][0] = _w;
        for (int i = 1; i <= L; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
            maxe[v][i] = max(maxe[v][i - 1], maxe[up[v][i - 1]][i - 1]);
        }
        for (auto& [u, w] : adj[v]) {
            if (u != p) {
                dfs(adj, u, v, w, d + 1);
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
    int get_ans(int k, int v) {
        int ans = 0;
        for (int i = 0; (k >> i) != 0; ++i) {
            if ((k >> i) & 1) {
                ans = max(ans, maxe[v][i]);
                v = up[v][i];
            }
        }
        return ans;
    }
    LCA(int n, int root, vector<vector<pair<int, int>>>& adj) {
        N = n;
        L = 32 - __builtin_clz(N);
        t = 0;
        tin.resize(N);
        tout.resize(N);
        depth.resize(N);
        up.assign(N, vector<int>(L + 1));
        maxe.assign(N, vector<int>(L + 1, 0));
        dfs(adj, root, root);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (!m) {
        return (0 - 0);
    }
    vector<tuple<int, int, int, int>> E(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = make_tuple(w, u - 1, v - 1, i);
    }
    sort(E.begin(), E.end());
    int64_t mst_sum = 0;
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> in_mst(m, false);
    union_find D(n);
    for (int i = 0; i < m; ++i) {
        int w = get<0>(E[i]), u = get<1>(E[i]), v = get<2>(E[i]), j = get<3>(E[i]); 
        if (D.find(u) != D.find(v)) {
            mst_sum += (int64_t)w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
            in_mst[j] = true;
            D.unite(u, v);
        }
    }
    LCA L(n, 0, adj);
    vector<int64_t> ans(m);
    for (int i = 0; i < m; ++i) {
        int j = get<3>(E[i]);
        if (in_mst[j]) {
            ans[j] = mst_sum;
            continue;
        }
        int w = get<0>(E[i]), u = get<1>(E[i]), v = get<2>(E[i]);
        int lca = L.lca(u, v);
        if (lca == u) {
            ans[j] = mst_sum - L.get_ans(L.depth[v] - L.depth[u], v) + w;
        } else if (lca == v) {
            ans[j] = mst_sum - L.get_ans(L.depth[u] - L.depth[v], u) + w;
        } else {
            ans[j] = mst_sum - max(L.get_ans(L.depth[u] - L.depth[lca], u), L.get_ans(L.depth[v] - L.depth[lca], v)) + w;
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
}
