//https://www.e-olymp.com/en/contests/13708/problems/133549
#include <bits/stdc++.h>
using namespace std;

void dfs (vector<vector<int>>& adj, vector<bool>& visited, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, v;
    cin >> N >> v;
    vector<vector<int>> adj(N + 1);
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int x;
            cin >> x;
            if (x) {
                adj[i].push_back(j);
            }
        }
    }
    dfs(adj, visited, v);
    cout << count(visited.begin(), visited.end(), true);
}
