/**
 *    author:  MaGnsi0
 *    created: 27/06/2021 19:06:04
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        int root = x;
        if (parent[root] != root) {
            parent[root] = find(parent[root]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        parent[a] = b;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    DSU D(n + 2);
    for (int i = 0; i < m; ++i) {
        int x;
        char c;
        cin >> c >> x;
        if (c == '-') {
            D.unite(x, x + 1);
        } else {
            int y = D.find(x);
            cout << (y == n + 1 ? -1 : y) << "\n";
        }
    }
}
