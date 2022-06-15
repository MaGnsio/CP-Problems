/**
 *    author:  MaGnsi0
 *    created: 16.04.2022 22:50:01
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    union_find D(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        D.unite(u - 1, v - 1);
    }
    vector<bool> visited(n, false);
    vector<vector<int>> length(2, vector<int>(n, 0));
    function<int(int, int, int)> DFS = [&](int v, int p, int x) {
        length[x][v] = (p == -1 ? 0 : length[x][p] + 1);
        int farest = v;
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            int pfarest = DFS(u, v, x);
            if (length[x][farest] < length[x][pfarest]) {
                farest = pfarest;
            }
        }
        return farest;
    };
    function<int(int)> get_diameter = [&](int v) {
        v = DFS(v, -1, 0);
        v = DFS(v, -1, 1);
        return length[1][v];
    };
    function<void(int, int, int)> set_diameter = [&](int v, int p, int l) {
        length[1][v] = l;
        visited[v] = true;
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            set_diameter(u, v, l);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            length[1][i] = get_diameter(i);
            set_diameter(i, -1, length[1][i]);
        }
    }
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            cin >> v;
            cout << length[1][D.find(v - 1)] << "\n";
        } else {
            int u, v;
            cin >> u >> v;
            int pu = D.find(u - 1), pv = D.find(v - 1);
            if (pu == pv) {
                continue;
            }
            int nl = max({length[1][pu], length[1][pv], (length[1][pu] + 1) / 2 + (length[1][pv] + 1) / 2 + 1});
            D.unite(u - 1, v - 1);
            length[1][D.find(u - 1)] = nl;
        }
    }
}
