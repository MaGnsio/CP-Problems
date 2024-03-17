/**
 *    author:  MaGnsi0
 *    created: 16.12.2023 14:08:54
**/
#include <bits/stdc++.h>

using namespace std;

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
    vector<int> s(n, 1);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int u : adj[v]) {
            if (u == p) { continue; }
            dfs(u, v);
            s[v] += s[u];
        }
    };
    dfs(0, -1);
    vector<int> ones;
    for (int u : adj[0]) {
        ones.push_back(s[u]);
    }
    sort(ones.begin(), ones.end());
    int ans = 0;
    for (int i = 0; i < (int)ones.size() - 1; ++i) {
        ans += ones[i];
    }
    cout << ans + 1;
}
