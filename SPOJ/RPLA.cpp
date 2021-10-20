/**
 *    author:  MaGnsi0
 *    created: 06/07/2021 20:39:04
**/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<pair<int, int>>& ans, int v, int r = 1) {
    visited[v] = true;
    ans.push_back({r, v});
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, ans, u, r + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<int> in_deg(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[v].push_back(u);
            in_deg[u]++;
        }
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> top_sort;
        for (int v = 0; v < n; ++v) {
            if (!in_deg[v]) {
                q.push(v);
            }
        }
        while(!q.empty()) {
            int v = q.top();
            q.pop();
            top_sort.push_back(v);
            for (auto& u : adj[v]) {
                in_deg[u]--;
                if (!in_deg[u]) {
                    q.push(u);
                }
            }
        }
        vector<bool> visited(n, false);
        vector<pair<int, int>> ans;
        for (auto& v : top_sort) {
            if (!visited[v]) {
                dfs(adj, visited, ans, v);
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Scenario #" << t << ":\n";
        for (auto& [r, v] : ans) {
            cout << r << " " << v << "\n";
        }
    }
}
