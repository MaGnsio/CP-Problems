/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 21:31:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int> ans;
    vector<bool> done(n, false);
    function<void(int, int)> dfs = [&](int v, int x) {
        done[v] = true;
        if (x) { ans.push_back(v); }
        for (int u : adj[v]) {
            if (done[u]) { continue; }
            dfs(u, x ^ 1);
        }
        if (!x) { ans.push_back(v); }
    };
    dfs(0, 0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
}
