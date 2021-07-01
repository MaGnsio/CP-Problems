//https://www.e-olymp.com/en/contests/8063/problems/67699
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<set<int>>& adj, vector<bool>& visited, int v, int par = -1) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (u == par) {
            continue;
        }
        if (visited[u]) {
            return true;
        }
        if (dfs(adj, visited, u, v)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<set<int>> adj(N + 1);
    vector<bool> visited(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 1; i <= N; ++i) {
        if (!visited[i] && dfs(adj, visited, i)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
