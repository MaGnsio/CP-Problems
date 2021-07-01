/**
 *    author:  MaGnsi0
 *    created: 29/06/2021 15:20:43
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int N) {
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
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
        parent[b] = a;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, q;
    cin >> n >> q;
    vector<int> l(q), r(q), c(q), color(n + 1, 0);
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i] >> c[i];
    }
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    reverse(c.begin(), c.end());
    DSU d(n + 2);
    for (int i = 0; i < q; ++i) {
        for (int v = d.find(l[i]); v <= r[i]; v = d.find(v)) {
            color[v] = c[i];
            d.unite(v + 1, v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << color[i] << "\n";
    }
}
