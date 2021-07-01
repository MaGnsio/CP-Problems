/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 00:35:50
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int res;
    vector<int> parent;
    vector<int> length;
    DSU(int N) {
        res = N - 1;
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
        if (length[a] < length[b]) {
            swap(a, b);
        }
        length[a] += length[b];
        parent[b] = a;
        res--;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    for (int T = 1; ; ++T) {
        int n, m;
        cin >> n >> m;
        if (!n && !m) {
            return 0;
        }
        DSU D(n + 1);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            D.unite(x, y);
        }
        cout << "Case " << T << ": " << D.res << "\n";
    }
}
