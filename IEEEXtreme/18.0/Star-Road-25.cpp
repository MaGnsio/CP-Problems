/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 03:45:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++; d[v]++;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (d[i] > 1) { continue; }
        vector<map<int, int>> dp(n);
        function<int(int, int, int)> dfs = [&](int v, int p, int last) {
            if (dp[v].count(last)) { return dp[v][last]; }
            int& best = dp[v][last];
            best = (a[v] > last);
            for (int u : adj[v]) {
                if (u == p) { continue; }
                best = max({best, dfs(u, v, max(a[v], last)) + (a[v] > last), dfs(u, v, last)});
            }
            return best;
        };
        ans = max(ans, dfs(i, -1, -1));
    }
    cout << ans;
}
