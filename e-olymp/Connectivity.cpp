//https://www.e-olymp.com/en/contests/13708/problems/133547
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<bool> visited(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, visited, 1);
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
