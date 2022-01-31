/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 19:38:17
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
    int res = n;
    DSU a(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (a.find(x - 1) != a.find(y - 1)) {
            a.unite(x - 1, y - 1);
            res--;
        }
    }
    cout << res;
}
