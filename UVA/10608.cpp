/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 01:04:09
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
        if (length[a] < length[b]) {
            swap(a, b);
        }
        length[a] += length[b];
        parent[b] = a;
    }
    int res() {
        int maxi = INT_MIN;
        for (auto& x : length) {
            maxi = max(maxi, x);
        }
        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        DSU D(n + 1);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            D.unite(x, y);
        }
        cout << D.res() << "\n";
    }
}
