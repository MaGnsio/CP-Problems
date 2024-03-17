/**
 *    author:  MaGnsi0
 *    created: 07.02.2024 20:06:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<set<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].emplace(v);
        adj[v].emplace(u);
    }
    int ans = 0;
    function<int(int, int)> dfs = [&](int v, int p) {
        int collected = 0;
        for (int u : adj[v]) {
            if (u == p) { continue; }
            collected += dfs(u, v);
        }
        if (collected == 0) {
            return 1;
        } else {
            ans += 2 * (collected - 1) + 1;
            return 0;
        }
    };
    int add = dfs(0, -1);
    ans += 2 * add;
    cout << ans;
}
