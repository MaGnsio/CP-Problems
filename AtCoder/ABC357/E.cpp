/**
 *    author:  MaGnsi0
 *    created: 08.06.2024 15:48:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n), adjT(n);
    for (int i = 0; i < n; ++i) {
        int j; cin >> j; j--;
        adj[i].push_back(j);
        adjT[j].push_back(i);
    }
    vector<bool> visited(n, false);
    vector<int> topological_order;
    function<void(int)> dfs1 = [&](int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs1(u);
            }
        }
        topological_order.push_back(v);
    };
    vector<int64_t> comp(n), comps;
    function<void(int)> dfs2 = [&](int v) {
        visited[v] = true;
        comp[v] = (int)comps.size() - 1;
        comps.back()++;
        for (auto& u : adjT[v]) {
            if (!visited[u]) {
                dfs2(u);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) { dfs1(i); }
    }
    reverse(topological_order.begin(), topological_order.end());
    fill(visited.begin(), visited.end(), false);
    for (int v : topological_order) {
        if (!visited[v]) {
            comps.push_back(0);
            dfs2(v);
        }
    }
    int m = (int)comps.size();
    vector<set<int>> adjc(m);
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (comp[i] == comp[j]) { continue; }
            adjc[comp[i]].insert(comp[j]);
        }
    }
    vector<int64_t> dp(m, -1);
    function<void(int)> solve = [&](int v) {
        if (dp[v] != -1) { return; }
        dp[v] = 0;
        for (int u : adjc[v]) {
            solve(u);
            dp[v] += dp[u] + comps[u];
        }
    };
    int64_t ans = 0;
    for (int i = 0; i < m; ++i) {
        solve(i);
        ans += comps[i] * comps[i];
        ans += comps[i] * dp[i];
    }
    cout << ans;
}
