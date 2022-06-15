/**
 *    author:  MaGnsi0
 *    created: 11.04.2022 05:30:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int64_t> s(n), dp(n);
    function<int(int, int)> DFS = [&](int v, int p) {
        s[v] = 1;
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            s[v] += DFS(u, v);
        }
        dp[v] = s[v];
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            dp[v] += dp[u];
        }
        return s[v];
    };
    int64_t ans = 0;
    function<void(int, int)> reroot = [&](int old_root, int new_root) {
        dp[old_root] -= (s[new_root] + dp[new_root]);
        s[old_root] -= s[new_root];
        dp[new_root] += (s[old_root] + dp[old_root]);
        s[new_root] += s[old_root];
    };
    function<void(int, int)> solve = [&](int v, int p) {
        ans = max(ans, dp[v]);
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            reroot(v, u);
            solve(u, v);
            reroot(u, v);
        }
    };
    DFS(0, -1);
    solve(0, -1);
    cout << ans;
}
