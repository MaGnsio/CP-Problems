//https://www.e-olymp.com/en/contests/12973/problems/123843
#include <bits/stdc++.h>
using namespace std;

bool dfs1(vector<vector<int>>& adj, vector<int>& color, int v) {
    color[v] = 1;
    for (auto& u : adj[v]) {
        if (color[u] == 1) {
            return true;
        } else if (color[u] == 0 && dfs1(adj, color, u)) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void dfs2(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& tSort, int v) {
    visited[v] = true;
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs2(adj, visited, tSort, u);
        }
    }
    tSort.push_back(v);
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> color(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        if (color[i] == 0 && dfs1(adj, color, i)) {
            cout << -1;
            return 0;
        }
    }
    vector<int> tSort;
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs2(adj, visited, tSort, i);
        }
    }
    reverse(tSort.begin(), tSort.end());
    for (auto& v : tSort) {
        cout << v << " ";
    }
}
