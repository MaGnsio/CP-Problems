/**
 *    author:  MaGnsi0
 *    created: 12.01.2024 20:13:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u]++, a[v]++;
    }
    int leafs = 0, pleafs = 0;
    for (int i = 0; i < n; ++i) {
        leafs += a[i] == 1;
    }
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j : adj[i]) {
            x |= a[j] == 1;
        }
        pleafs += x;
    }
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int u : adj[v]) {
            if (u == p) { continue; }
            b[u] = b[v] + 1;
            dfs(u, v);
        }
    };
    dfs(0, -1);
    bool all_odd = true, all_even = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) { continue; }
        all_odd = all_odd && b[i] % 2 == 1;
        all_even = all_even && b[i] % 2 == 0;
    }
    cout << (all_odd || all_even ? 1 : 3) << " " << (n - 1) - leafs + pleafs;
}
