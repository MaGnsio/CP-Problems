/**
 *    author:  MaGnsi0
 *    created: 30.01.2024 18:03:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; ++v) {
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }
    vector<int> farthest(n), depth(n);
    function<void(int)> dfs = [&](int v) {
        for (int u : adj[v]) {
            depth[u] = depth[v] + 1;
            dfs(u);
            farthest[v] = max(farthest[v], farthest[u] + 1);
        }
        sort(adj[v].begin(), adj[v].end(), [&](int x, int y) {
                return farthest[x] < farthest[y];
            });
    };
    dfs(0);
    int ans = 2 * (n - 1) - farthest[0];
    vector<int> a;
    for (int v = 0; v < n; ++v) {
        if (!adj[v].empty()) { adj[v].pop_back(); }
        for (int u : adj[v]) {
            if (depth[v] < farthest[u] + 1) {
                a.push_back(farthest[u] - depth[v] + 1);
            }
        }
    }
    sort(a.rbegin(), a.rend());
    if (a.size() > k) { a.resize(k); }
    for (int x : a) { ans -= x; }
    cout << ans;
}
