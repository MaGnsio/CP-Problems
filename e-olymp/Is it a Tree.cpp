//https://www.e-olymp.com/en/contests/8063/problems/67705
#include <bits/stdc++.h>
using namespace std;

void dfs1(vector<vector<int>>& adj, vector<bool>& visited, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs1(adj, visited, u);
        }
    }
}

bool dfs2(vector<vector<int>>& adj, vector<bool>& visited, int v, int par = -1) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (u == par) {
            continue;
        }
        if (visited[u]) {
            return false;
        }
        if (!dfs2(adj, visited, u, v)) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
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
    dfs1(adj, visited, 1);
    if (count(visited.begin(), visited.end(), true) != N) {
        cout << "NO";
        return 0;
    }
    visited.assign(N + 1, false);
    cout << (dfs2(adj, visited, 1) ? "YES" : "NO");
}
