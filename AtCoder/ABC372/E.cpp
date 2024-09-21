/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 15:31:24
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, length;
    vector<vector<int>> comps;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
        comps.resize(n);
        for (int i = 0; i < n; ++i) {
            comps[i].push_back(-i);
        }
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
        for (int v : comps[Py]) {
            comps[Px].push_back(v);
        }
        comps[Py].clear();
        sort(comps[Px].begin(), comps[Px].end());
        while ((int)comps[Px].size() > 10) {
            comps[Px].pop_back();
        }
    }
    int get(int v, int k) {
        int Pv = find(v);
        if ((int)comps[Pv].size() < k) { return -1; }
        return 1 - comps[Pv][k - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    union_find dsu(n);
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            dsu.unite(u, v);
        } else {
            int v; cin >> v; v--;
            int k; cin >> k;
            cout << dsu.get(v, k) << "\n";
        }
    }
}
