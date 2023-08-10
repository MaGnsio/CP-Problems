/**
 *    author:  MaGnsi0
 *    created: 07.06.2023 05:20:32
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
    vector<int64_t> U(m), V(m), W(m), I(m);
    for (int i = 0; i < m; ++i) {
        cin >> U[i] >> V[i] >> W[i];
        U[i]--, V[i]--, I[i] = i;
    }
    sort(I.begin(), I.end(), [&](int i, int j) {
            return W[i] < W[j];
        });
    int64_t ans = 0;
    union_find dsu(n);
    for (int i = 0; i < m; ++i) {
        int j = I[i];
        if (dsu.find(U[j]) != dsu.find(V[j])) {
            dsu.unite(U[j], V[j]);
        } else {
            ans += W[j];
        }
    }
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(dsu.find(i));
    }
    cout << (s.size() == 1 ? ans : -1);
}
