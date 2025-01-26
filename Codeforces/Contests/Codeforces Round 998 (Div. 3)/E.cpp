/**
 *    author:  MaGnsi0
 *    created: 26.01.2025 22:26:42
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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m1; cin >> m1;
        int m2; cin >> m2;
        vector<pair<int, int>> e1(m1);
        for (int i = 0; i < m1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            e1[i] = {u, v};
        }
        union_find dsu2(n);
        for (int i = 0; i < m2; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            dsu2.unite(u, v);
        }
        int ans = 0;
        union_find dsu1(n);
        for (auto [u, v] : e1) {
            if (dsu2.find(u) != dsu2.find(v)) {
                ans++;
            } else {
                dsu1.unite(u, v);
            }
        }
        vector<set<int>> p(n);
        for (int i = 0; i < n; ++i) {
            p[dsu2.find(i)].insert(dsu1.find(i));
        }
        for (int i = 0; i < n; ++i) {
            ans += max((int)p[i].size() - 1, 0);
        }
        cout << ans << "\n";
    }
}
