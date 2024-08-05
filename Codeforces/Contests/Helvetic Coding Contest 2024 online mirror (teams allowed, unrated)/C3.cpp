/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 19:01:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int t; cin >> t;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<unordered_map<int, int>> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i][-1] = -1;
        for (int j : adj[i]) {
            dp[i][j] = -1;
        }
    }
    function<int(int, int)> solve = [&](int v, int p) {
        if (dp[v][p] != -1) {
            return dp[v][p];
        }
        dp[v][p] = 0;
        for (int u : adj[v]) {
            if (u == p) { continue; }
            dp[v][p] |= !solve(u, v);
            if (dp[v][p]) { break; }
        }
        return dp[v][p];
    };
    while (t--) {
        int v; cin >> v; v--;
        cout << (solve(v, -1) ? "Ron" : "Hermione") << "\n";
    }
}
