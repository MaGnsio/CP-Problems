/**
 *    author:  MaGnsi0
 *    created: 11.12.2021 22:51:12
**/
#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
        length.resize(N);
        length.assign(N, 1);
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
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> y[i];
    }
    int q;
    cin >> q;
    vector<int> a(q), b(q, -1);
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            cin >> b[i];
            b[i]--;
        }
    }
    DSU d(n + 1);
    set<int> r(b.begin(), b.end());
    r.erase(-1);
    for (int i = 0; i < m; ++i) {
        if (r.count(i) == 0) {
            d.unite(x[i], y[i]);
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> res;
    for (int i = 0; i < q; ++i) {
        if (a[i] == 1) {
            d.unite(x[b[i]], y[b[i]]);
        } else {
            res.push_back(d.length[d.parent[0]]);
        }
    }
    reverse(res.begin(), res.end());
    for (auto& x : res) {
        cout << x - 1 << "\n";
    }
}
