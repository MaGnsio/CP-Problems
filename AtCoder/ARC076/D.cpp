/**
 *    author:  MaGnsi0
 *    created: 01/07/2021 19:05:52
**/
#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v;
    long long w;
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
    int n;
    cin >> n;
    vector<pair<int, int>> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> y[i].first;
        x[i].second = y[i].second = i;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<edge> edges;
    for (int i = 1; i < n; ++i) {
        edges.push_back({x[i].second, x[i - 1].second, x[i].first - x[i - 1].first});
        edges.push_back({y[i].second, y[i - 1].second, y[i].first - y[i - 1].first});
    }
    sort(edges.begin(), edges.end());
    long long res = 0;
    DSU d(n);
    for (auto& [u, v, w] : edges) {
        if (d.find(u) == d.find(v)) {
            continue;
        }
        d.unite(u, v);
        res += w;
    }
    cout << res;
}
