/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 15:32:08
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, length;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
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
    union_find dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u - 1, v - 1);
    }
    int k;
    cin >> k;
    set<pair<int, int>> s;
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        assert(dsu.find(u - 1) != dsu.find(v - 1));
        s.emplace(dsu.find(u - 1), dsu.find(v - 1));
        s.emplace(dsu.find(v - 1), dsu.find(u - 1));
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        bool ok = s.count(make_pair(dsu.find(u - 1), dsu.find(v - 1)));
        cout << (ok ? "No" : "Yes") << "\n";
    }
}
