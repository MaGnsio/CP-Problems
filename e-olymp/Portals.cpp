//https://www.e-olymp.com/en/contests/8063/problems/67703
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& cost, int& x, int v) {
    visited[v] = true;
    x = min(x, cost[v]);
    for (auto& u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, visited, cost, x, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<int> cost(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
    }
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(N + 1, false);
    vector<int> CC;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            int x = INT_MAX;
            dfs(adj, visited, cost, x, i);
            CC.push_back(x);
        }
    }
    if (CC.size() == 1) {
        cout << 0;
    } else {
        int minC = 0;
        for (auto& x : CC) {
            minC += x;
        }
        cout << minC + *min_element(CC.begin(), CC.end()) * (CC.size() - 2);
    }
}
