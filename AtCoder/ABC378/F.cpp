/**
 *    author:  MaGnsi0
 *    created: 02.11.2024 16:57:41
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
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> deg2(n, false), deg3(n, false);
    for (int v = 0; v < n; ++v) {
        deg2[v] = (int)adj[v].size() == 2;
        deg3[v] = (int)adj[v].size() == 3;
    }
    union_find dsu3(n);
    for (int v = 0; v < n; ++v) {
        if (!deg3[v]) { continue; }
        for (int u : adj[v]) {
            if (!deg3[u]) { continue; }
            dsu3.unite(u, v);
        }
    }
    map<int, int> mp;
    for (int v = 0; v < n; ++v) {
        if (!deg2[v]) { continue; }
        for (int u : adj[v]) {
            if (!deg3[u]) { continue; }
            mp[dsu3.find(u)]++;
        }
    }
    int64_t ans = 0;
    for (auto [_, x] : mp) {
        ans += 1LL * x * (x - 1) / 2;
    }
    cout << ans;
}
