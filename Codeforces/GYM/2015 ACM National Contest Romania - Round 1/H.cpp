#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> root;
    vector<int> rank;
    DSU(int N) {
        root = vector<int>(N);
        iota(root.begin(), root.end(), 0);
        rank = vector<int>(N, 0);
    }
    int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }
    void unite(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) {
            return;
        }
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        root[b] = a;
        rank[a] += (rank[a] == rank[b]);
    }
};

int main() {
    freopen("meciul.in", "r", stdin);
    freopen("meciul.out", "w", stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        DSU D(2 * n + 2);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            if (D.find(x) == D.find(y)) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            D.unite(x, y + n);
            D.unite(x + n, y);
        }
    }
}
