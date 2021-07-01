/**
 *    author:  MaGnsi0
 *    created: 28/06/2021 01:44:13
**/
#include <bits/stdc++.h>
#define int long long
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
        int res = 1;
        set<int> s;
        for (int i = 1; i < parent.size(); ++i) {
            find(i);
        }
        for (auto& x : parent) {
            s.insert(x);
        }
        for (auto& x : s) {
            res *= (1LL << (length[x] - 1));
        }
        return res;
    }
};

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    DSU D(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        D.unite(x, y);
    }
    cout << D.solve();
}
