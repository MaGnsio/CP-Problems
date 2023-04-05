/**
 *    author:  MaGnsi0
 *    created: 08.02.2023 09:53:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].emplace_back(v - 1, 0);
        adj[v - 1].emplace_back(u - 1, 1);
    }
    vector<int> dp(n, 0);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (auto& [u, w] : adj[v]) {
            if (u == p) { continue; }
            dfs(u, v);
            dp[v] += dp[u] + w;
        }
    };
    dfs(0, -1);
    vector<int> ans(n);
    function<void(int, int)> solve = [&](int v, int p) {
        ans[v] = dp[v];
        for (auto& [u, w] : adj[v]) {
            if (u == p) { continue; }
            int oldv = dp[v];
            int oldu = dp[u];
            dp[v] = oldv - oldu - w;
            dp[u] = oldu + dp[v] + (w ^ 1);
            solve(u, v);
            dp[v] = oldv;
            dp[u] = oldu;
        }
    };
    solve(0, -1);
    int res = *min_element(ans.begin(), ans.end());
    cout << res << "\n";
    for (int i = 0; i < n; ++i) {
        if (ans[i] == res) {
            cout << i + 1 << " ";
        }
    }
}
