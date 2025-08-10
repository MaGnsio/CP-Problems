/**
 *    author:  MaGnsi0
 *    created: 10.08.2025 17:59:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> d(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            d[u]++, d[v]++;
        }
        int leafs = (int)count(d.begin(), d.end(), 1), ans = leafs;
        for (int u = 0; u < n; ++u) {
            int x = d[u] == 1;
            for (int v : adj[u]) {
                x += d[v] == 1;
            }
            ans = min(ans, leafs - x);
        }
        cout << ans << "\n";
    }
}
