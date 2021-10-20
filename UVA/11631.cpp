/**
 *    author:  MaGnsi0
 *    created: 01/07/2021 04:36:28
**/
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    bool operator<(edge e) {
        return (this -> w < e.w);
    }
};

struct DSU {
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(N, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        if (length[a] < length[b]) {
            swap(a, b);
        }
        length[a] += length[b];
        parent[b] = a;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    while ((cin >> n >> m) && (n || m)) {
        int res = 0;
        vector<edge> edges(m);
        for (auto& [u, v, w] : edges) {
            cin >> u >> v >> w;
            res += w;
        }
        sort(edges.begin(), edges.end());
        DSU d(n + 1);
        for (auto& [u, v, w] : edges) {
            if (d.find(u) == d.find(v)) {
                continue;
            }
            d.unite(u, v);
            res -= w;
        }
        cout << res << "\n";
    }
}
