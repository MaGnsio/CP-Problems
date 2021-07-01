/**
 *    author:  MaGnsi0
 *    created: 01/07/2021 05:31:24
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
    void reset() {
        iota(parent.begin(), parent.end(), 0);
        fill(length.begin(), length.end(), 1);
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
    int n, m, res = 0;
    cin >> n >> m;
    vector<edge> edges(m);
    for (auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
    }
    sort(edges.begin(), edges.end());
    DSU d(n + 1);
    vector<int> edge_index;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (d.find(u) == d.find(v)) {
            continue;
        }
        d.unite(u, v);
        edge_index.push_back(i);
        res += w;
    }
    cout << res << " ";
    res = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        int temp = 0, cnt = 0;
        d.reset();
        for (int j = 0; j < m; ++j) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (edge_index[i] == j || d.find(u) == d.find(v)) {
                continue;
            }
            d.unite(u, v);
            temp += w;
            cnt++;
        }
        if (cnt == n - 1) {
            res = min(res, temp);
        }
    }
    cout << res;
}
