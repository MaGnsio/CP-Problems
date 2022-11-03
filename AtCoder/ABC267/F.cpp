/**
 *    author:  MaGnsi0
 *    created: 03.09.2022 13:58:12
**/
#include <bits/stdc++.h>

using namespace std;

struct least_common_ancestor {
    int N, L;
    vector<int> depth;
    vector<vector<int>> up;
    void dfs(vector<vector<int>>& adj, int v, int p, int d = 0) {
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
    }
    int Kth_ancestor(int k, int v) {
        for (int i = 0; (k >> i) != 0; ++i) {
            if ((k >> i) & 1) {
                v = up[v][i];
            }
        }
        return v;
    }
    least_common_ancestor(int n, int root, vector<vector<int>>& adj) {
        N = n;
        L = 32 - __builtin_clz(N);
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
    vector<vector<int>> d(2, vector<int>(n));
    function<void(int, int, int)> dfs = [&](int v, int p, int j) {
        d[j][v] = (p == -1 ? 0 : d[j][p] + 1);
        for (auto& u : adj[v]) {
            if (u != p) {
                dfs(u, v, j);
            }
        }
    };
    int x, y;
    dfs(0, -1, 0);
    int maxd = *max_element(d[0].begin(), d[0].end());
    for (int i = 0; i < n; ++i) {
        if (d[0][i] == maxd) {
            x = i;
        }
    }
    dfs(x, -1, 1);
    maxd = *max_element(d[1].begin(), d[1].end());
    for (int i = 0; i < n; ++i) {
        if (d[1][i] == maxd) {
            y = i;
        }
    }
    least_common_ancestor lca1(n, x, adj);
    least_common_ancestor lca2(n, y, adj);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int v, k;
        cin >> v >> k;
        if (lca1.depth[v - 1] >= k) {
            cout << lca1.Kth_ancestor(k, v - 1) + 1 << "\n";
        } else if (lca2.depth[v - 1] >= k) {
            cout << lca2.Kth_ancestor(k, v - 1) + 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}
