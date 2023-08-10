/**
 *    author:  MaGnsi0
 *    created: 01.08.2023 10:08:10
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int dfs_time = 0;
    vector<int> in(n, -1), low(n, -1);
    set<pair<int, int>> bridges;
    vector<bool> visited(n, false);
    function<void(int, int)> dfs = [&](int v, int p) {
        visited[v] = true;
        in[v] = low[v] = dfs_time++;
        for (int u : adj[v]) {
            if (u == p) { continue; }
            if (visited[u]) {
                low[v] = min(low[v], in[u]);
            } else {
                dfs(u, v);
                low[v] = min(low[v], low[u]);
                if (in[v] < low[u]) {
                    bridges.emplace(u, v);
                    bridges.emplace(v, u);
                }
            }
        }
    };
    dfs(0, -1);
    union_find dsu(n);
    for (int v = 0; v < n; ++v) {
        for (int u : adj[v]) {
            if (bridges.count({u, v})) { continue; }
            dsu.unite(u, v);
        }
    }
    adj = vector<vector<int>>(n);
    for (auto [u, v] : bridges) {
        adj[dsu.find(u)].push_back(dsu.find(v));
    }
    function<vector<int>(int)> bfs = [&](int source) {
        vector<int> d(n, -1);
        queue<int> q;
        q.push(source), d[source] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (d[u] != -1) { continue; }
                q.push(u), d[u] = d[v] + 1;
            }
        }
        return d;
    };
    int v = dsu.find(bridges.begin() -> first);
    vector<int> b = bfs(v);
    int max_d = *max_element(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        if (b[i] == max_d) {
            b = bfs(i);
            break;
        }
    }
    int ans = *max_element(b.begin(), b.end());
    cout << ans;
}
