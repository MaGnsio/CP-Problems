/**
 *    author:  MaGnsi0
 *    created: 18.02.2023 12:54:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int> in(n);
    vector<bool> visited(n, false);
    function<void(int, int)> dfs = [&](int v, int p) {
        visited[v] = true;
        for (auto& u : adj[v]) {
            if (u == p) { continue; }
            if (!visited[u]) {
                in[u] = in[v] + 1;
                dfs(u, v);
            } else {
                if ((in[v] & 1) == (in[u] & 1) && in[u] - in[v] > 2) {
                    cout << "No";
                    exit(0);
                }
            }
        }
    };
    dfs(0, -1);
    cout << "Yes";
}
