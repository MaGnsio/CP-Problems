/**
 *    author:  MaGnsi0
 *    created: 28.02.2025 17:13:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int S; cin >> S; S--;
        int E; cin >> E; E--;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        function<void(int, int)> go = [&](int v, int p) {
            for (int u : adj[v]) {
                if (u == p) { continue; }
                go(u, v);
            }
            cout << v + 1 << " ";
        };
        go(E, -1);
        cout << "\n";
    }
}
