/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 02:17:33
**/
#include <bits/stdc++.h>
using namespace std;

struct DSU{
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
    int solve() {
        set<int> s;
        for (int i = 1; i < parent.size(); ++i) {
            s.insert(find(i));
        }
        return (s.size() - 1);
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, d = 1;
    cin >> n >> m;
    vector<vector<int>> v(m + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        if (k) {
            d = 0;
        }
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
    }
    DSU D(n + 1);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j < v[i].size(); ++j) {
            D.unite(v[i][0], v[i][j]);
        }
    }
    cout << D.solve() + d;
}
