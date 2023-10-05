/**
 *    author:  MaGnsi0
 *    created: 19.09.2023 19:57:00
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

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
    int n;
    cin >> n;
    union_find dsu(N);
    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        int v; cin >> v;
        cout << (dsu.find(u) == dsu.find(v) ? "Y" : "N") << "\n";
        dsu.unite(u, v);
    }
}
