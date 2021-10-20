/**
 *    author:  MaGnsi0
 *    created: 16/08/2021 20:37:01
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
        length[Px] += Py;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU d1(n), d2(n);
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        d1.unite(u, v);
    }
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        d2.unite(u, v);
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (d1.find(i) != d1.find(j) && d2.find(i) != d2.find(j)) {
                d1.unite(i, j);
                d2.unite(i, j);
                res.push_back({i + 1, j + 1});
            }
        }
    }
    cout << (int)res.size() << "\n";
    for (auto& [u, v] : res) {
        cout << u << " " << v << "\n";
    }
}
