/**
 *    author:  MaGnsi0
 *    created: 01/07/2021 18:32:11
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
    vector<bool> ok;
    DSU(int N) {
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(N, 1);
        ok = vector<bool>(N, true);
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
        ok[y] = false;
        if (length[a] < length[b]) {
            swap(a, b);
        }
        length[a] += length[b];
        parent[b] = a;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, res = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> m;
    }
    vector<edge> edges(m);
    for (auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
    }
    sort(edges.begin(), edges.end());
    DSU d(n + 1);
    for (auto& [u, v, w] : edges) {
        if (!d.ok[v] || d.find(u) == d.find(v)) {
            continue;
        }
        d.unite(u, v);
        res += w;
        cnt++;
    }
    cout << (cnt == n - 1 ? res : -1);
}
