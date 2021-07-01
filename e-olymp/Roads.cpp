//https://www.e-olymp.com/en/contests/8063/problems/67707
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<set<int>>& adj, vector<bool>& visited, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M, CC = 0;
    cin >> N >> M;
    vector<set<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            continue;
        }
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(adj, visited, i);
            CC++;
        }
    }
    cout << CC - 1;
}
