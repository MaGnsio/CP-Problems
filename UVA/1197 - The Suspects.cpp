/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 01:16:25
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(N, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        if ((b == 0) || (a && length[a] < length[b])) {
            swap(a, b);
        }
        length[a] += length[b];
        parent[b] = a;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    while ((cin >> n >> m) && (n || m)) {
        DSU D(n);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            vector<int> v(k);
            for (int j = 0; j < k; ++j) {
                cin >> v[j];
            }
            for (int j = 1; j < k; ++j) {
                D.unite(v[0], v[j]);
            }
        }
        cout << D.length[0] << "\n";
    }
}
