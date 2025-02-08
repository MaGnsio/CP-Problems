/**
 *    author:  MaGnsi0
 *    created: 08.02.2025 14:18:56
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
    int n; cin >> n;
    int m; cin >> m;
    vector<pair<int, int>> caples(m);
    for (int i = 0; i < m; ++i) {
        cin >> caples[i].first; caples[i].first--;
        cin >> caples[i].second; caples[i].second--;
    }
    set<int> usable;
    union_find dsu(n);
    for (int i = 0; i < m; ++i) {
        auto [u, v] = caples[i];
        if (dsu.find(u) == dsu.find(v)) {
            usable.insert(i);
        } else {
            dsu.unite(u, v);
        }
    }
    set<int> parents;
    for (int i = 0; i < n; ++i) {
        parents.insert(dsu.find(i));
    }
    vector<tuple<int, int, int>> operations;
    while (parents.size() > 1) {
        assert(!usable.empty());
        int j = *usable.begin(); usable.erase(j);
        auto [u, v] = caples[j];
        assert(dsu.find(u) == dsu.find(v));
        int p = dsu.find(u);
        int np = (*parents.begin() == p ? *parents.rbegin() : *parents.begin());
        parents.erase(p);
        parents.erase(np);
        dsu.unite(p, np);
        parents.insert(dsu.find(p));
        operations.emplace_back(j + 1, u + 1, np + 1);
    }
    cout << (int)operations.size() << "\n";
    for (auto [j, u, v] : operations) {
        cout << j << " " << u << " " << v << "\n";
    }
}
