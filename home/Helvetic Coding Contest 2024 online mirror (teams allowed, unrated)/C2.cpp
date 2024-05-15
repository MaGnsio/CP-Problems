/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 18:57:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int t; cin >> t;
    vector<int> d(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++, d[v]++;
    }
    function<bool(int, int)> solve = [&](int v, int p) {
        bool res = false;
        for (int u : adj[v]) {
            if (u == p) { continue; }
            res |= !solve(u, v);
        }
        return res;
    };
    while (t--) {
        int v; cin >> v; v--;
        cout << (solve(v, -1) ? "Ron" : "Hermione") << "\n";
    }
}
