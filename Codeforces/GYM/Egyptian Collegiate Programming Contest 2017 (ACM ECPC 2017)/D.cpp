/**
 *    author:  MaGnsi0
 *    created: 02/07/2021 04:56:12
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

struct edge {
    int u, v, w;
    bool operator<(edge e) {
        return (this -> w > e.w);
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

int32_t main() {
    freopen("dream.in", "r", stdin);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, res = 0;
        cin >> n;
        vector<vector<int>> v(N);
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            for (int j = 1; j <= x; ++j) {
                if (x % j == 0) {
                    v[j].push_back(i);
                }
            }
        }
        vector<edge> edges;
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < v[i].size(); ++j) {
                edges.push_back({v[i][0], v[i][j], i});
            }
        }
        sort(edges.begin(), edges.end());
        DSU d(n);
        for (auto& [u, v, w] : edges) {
            if (d.find(u) == d.find(v)) {
                continue;
            }
            d.unite(u, v);
            res += w;
        }
        cout << "Case " << t << ": " << res << "\n";
    }
}
