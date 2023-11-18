/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 21:47:25
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
    int T;
    cin >> T;
    while (T--) {
        int n, m, Q;
        cin >> n >> m >> Q;
        union_find dsu(n);
        for (int i = 0; i < m; ++i) {
            int u; cin >> u;
            int v; cin >> v;
            dsu.unite(u - 1, v - 1);
        }
        string ans = "";
        while (Q--) {
            int u; cin >> u;
            int v; cin >> v;
            ans += (dsu.find(u - 1) == dsu.find(v - 1) ? "1" : "0");
        }
        cout << ans << "\n";
    }
}
