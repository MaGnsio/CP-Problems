/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 22:25:19
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> U(m), V(m);
        vector<bool> bridge(m, false);
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            cin >> U[i]; U[i]--;
            cin >> V[i]; V[i]--;
            adj[U[i]].emplace_back(V[i], i);
            adj[V[i]].emplace_back(U[i], i);
        }
        int dfs_time = 0;
        vector<int> in(n), low(n);
        vector<bool> visited(n, false);
        function<void(int, int)> dfs = [&](int v, int p) {
            visited[v] = true;
            in[v] = low[v] = dfs_time++;
            for (auto [u, j] : adj[v]) {
                if (u == p) { continue; }
                if (visited[u]) {
                    low[v] = min(low[v], in[u]);
                } else {
                    dfs(u, v);
                    low[v] = min(low[v], low[u]);
                    if (in[v] < low[u]) {
                        bridge[j] = true;
                    }
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                dfs(i, -1);
            }
        }
        union_find dsu(n);
        visited = vector<bool>(n, false);
        adj = vector<vector<pair<int, int>>>(n);
        for (int i = 0; i < m; ++i) {
            if (dsu.find(U[i]) == dsu.find(V[i])) {
                assert(bridge[i] == false);
                continue;
            }
            dsu.unite(U[i], V[i]);
            adj[U[i]].emplace_back(V[i], bridge[i]);
            adj[V[i]].emplace_back(U[i], bridge[i]);
        }
        function<pair<int, int>(int)> bfs = [&](int source) {
            queue<int> Q;
            vector<int> d(n, -1);
            Q.push(source), d[source] = 0;
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                visited[v] = true;
                for (auto [u, w] : adj[v]) {
                    if (d[u] != -1) { continue; }
                    Q.push(u), d[u] = d[v] + w;
                }
            }
            pair<int, int> res = {-1, -1};
            for (int i = 0; i < n; ++i) {
                res = max(res, make_pair(d[i], i));
            }
            return res;
        };
        int ans = m, bridges = count(bridge.begin(), bridge.end(), true);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) { continue; }
            ans = min(ans, bridges - bfs(bfs(i).second).first);
        }
        cout << ans << "\n";
    }
}
