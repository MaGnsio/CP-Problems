/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 05:16:48
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge {
    int u, v, w;
    bool operator<(edge a) {
        return this -> w < a.w;
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
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, mod = 1e9, ans = 0;
    cin >> n >> m;
    DSU D(n + 1);
    vector<edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    vector<int> pre_removed(m);
    for (int i = m - 1; i >= 0; --i) {
        pre_removed[i] = edges[i].w + (i != m - 1 ? pre_removed[i + 1] : 0); 
    }
    for (int i = 0; i < m; ++i) {
        int a = D.find(edges[i].u), b = D.find(edges[i].v);
        int x = D.length[a], y = D.length[b];
        if (a != b) {
            ans = (ans + pre_removed[i] * x * y) % mod;
        }
        D.unite(edges[i].u, edges[i].v);
    }
    cout << ans;
}
