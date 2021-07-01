/**
 *    author:  MaGnsi0
 *    created: 01/07/2021 03:50:08
**/
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v;
    double w;
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

double dist(double x1, double y1, double x2, double y2) {
    double a = x1 - x2;
    double b = y1 - y2;
    double d = sqrt((a * a) + (b * b));
    return d;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n;
        vector<double> x(n + 1), y(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> x[i] >> y[i];
        }
        vector<edge> edges;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                edges.push_back({i, j, dist(x[i], y[i], x[j], y[j])});
            }
        }
        cin >> m;
        DSU d(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            d.unite(u, v);
        }
        sort(edges.begin(), edges.end());
        vector<pair<int, int>> mst;
        for (auto& [u, v, w] : edges) {
            if (d.find(u) == d.find(v)) {
                continue;
            }
            d.unite(u, v);
            mst.push_back({u, v});
        }
        if (mst.empty()) {
            cout << "No new highways need\n";
        } else {
            for (auto& [u, v] : mst) {
                cout << u << " " << v << "\n";
            }
        }
        if (T) {
            cout << "\n";
        }
    }
}
