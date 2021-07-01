/**
 *    author:  MaGnsi0
 *    created: 24/06/2021 00:23:57
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
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
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
    int n, m;
    cin >> n >> m;
    DSU a(n + 1);
    while (m--) {
        int x, y;
        string c;
        cin >> c >> x >> y;
        if (c == "union") {
            a.unite(x, y);
        } else {
            cout << (a.find(x) == a.find(y) ? "YES\n" : "NO\n");
        }
    }
}
