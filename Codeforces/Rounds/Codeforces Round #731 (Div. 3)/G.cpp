/**
 *    author:  MaGnsi0
 *    created: 10/07/2021 17:37:09
**/
#include <bits/stdc++.h>
using namespace std;

void dfs1(vector<vector<int>>& adj, vector<int>& color, vector<int>& c, int v) {
    color[v] = 1;
    for (auto& u : adj[v]) {
        if (color[u] == 1) {
            c.push_back(u);
        }
        if (color[u] == 0) {
            dfs1(adj, color, c, u);
        }
    }
    color[v] = 2;
}

void dfs2(vector<vector<int>>& adj, vector<int>& ans, int v) {
    ans[v] = -1;
    for (auto& u : adj[v]) {
        if (ans[u] == 0) {
            dfs2(adj, ans, u);
        }
    }
}

void dfs3(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans, int v) {
    visited[v] = true;
    if (ans[v] != -1) {
        ans[v] = 1;
    }
    for (auto& u : adj[v]) {
        if (visited[u] && ans[u] != -1) {
            ans[u] = 2;
        }
        if (!visited[u]) {
            dfs3(adj, visited, ans, u);
        }
    }
}

void dfs4(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans, int v) {
    visited[v] = true;
    if (ans[v] != -1) {
        ans[v] = 2;
    }
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs4(adj, visited, ans, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<int> ans(n + 1, 0), color(n + 1, 0), c;
        dfs1(adj, color, c, 1);
        for (auto& v : c) {
            if (ans[v] == 0) {
                dfs2(adj, ans, v);
            }
        }
        vector<bool> visited(n + 1, false);
        dfs3(adj, visited, ans, 1);
        visited.assign(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            if (ans[i] == 2 && !visited[i]) {
                dfs4(adj, visited, ans, i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
