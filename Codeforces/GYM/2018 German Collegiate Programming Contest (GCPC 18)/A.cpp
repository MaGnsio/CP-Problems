/**
 *    author:  MaGnsi0
 *    created: 21/09/2021 17:49:03
**/
#include <bits/stdc++.h>
using namespace std;

int get(int d, int x, int y) {
    return (d * x + y);
}

struct LCA {
    int n, m;
    vector<int> depth, first, euler;
    vector<vector<int>> mat;
    void dfs(const vector<vector<int>>& tree, int cur_depth, int v, int par) {
        depth[v] = cur_depth;
        first[v] = (int)euler.size();
        euler.push_back(v);
        for (auto& u : tree[v]) {
            if (u != par) {
                dfs(tree, cur_depth + 1, u, v);
                euler.push_back(v);
            }
        }
    }
    LCA(const vector<vector<int>>& tree, const int root) {
        n = (int)tree.size();
        depth = first = vector<int>(n);
        euler.reserve(2 * n);
        dfs(tree, 0, root, -1);
        m = (int)euler.size();
        int max_log = 32 - __builtin_clz(m);
        mat.resize(max_log);
        mat[0] = euler;
        for (int j = 1; j < max_log; ++j) {
            mat[j].resize(m - (1 << j) + 1);
            for (int i = 0; i <= m - (1 << j); ++i) {
                int u = mat[j - 1][i];
                int v = mat[j - 1][i + (1 << (j - 1))];
                mat[j][i] = (depth[u] <= depth[v] ? u : v);
            }
        }
    }
    int get(int u, int v) {
        int from = first[u];
        int to = first[v];
        if (from > to) {
            swap(from, to);
        }
        assert(0 <= from && from <= to && to <= m - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        int a = mat[lg][from];
        int b = mat[lg][to - (1 << lg) + 1];
        return (depth[a] <= depth[b] ? a : b);
    }
    int solve(int u, int v) {
        int x = get(u, v);
        if (x == u || x == v) {
            return abs(depth[u] - depth[v]);
        } else {
            return (depth[u] + depth[v] - 2 * depth[x]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int h, w;
    cin >> h >> w;
    vector<string> g(h + 1);
    cin.ignore();
    for (int i = 0; i <= h; ++i) {
        getline(cin, g[i]);
    }
    vector<vector<int>> adj(h * w);
    for (int i = 1, x = 0; i <= h; ++i, ++x) {
        for (int j = 1, y = 0; j <= 2 * w; j += 2, ++y) {
            int u = get(w, x, y);
            if (g[i][j] == ' ' && get(w, x + 1, y) < h * w) {
                int v = get(w, x + 1, y);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            if (g[i][j + 1] == ' ' && get(w, x, y + 1) < h * w) {
                int v = get(w, x, y + 1);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
    vector<vector<int>> tree(h * w);
    queue<int> q;
    vector<int> visited(h * w, false);
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
        }
    }
    LCA lca(tree, 0);
    int m, x, y, u, v;
    long long res = 0;
    cin >> m >> x >> y;
    u = get(w, x - 1, y - 1);
    while (--m) {
        cin >> x >> y;
        v = get(w, x - 1, y - 1);
        res += (long long)lca.solve(u, v);
        u = v;
    }
    cout << res;
}
