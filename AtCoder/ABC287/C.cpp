/**
 *    author:  MaGnsi0
 *    created: 01.02.2023 21:44:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        deg[u - 1]++, deg[v - 1]++;
    }
    int deg1 = 0, deg2 = 0;
    for (int i = 0; i < n; ++i) {
        deg1 += deg[i] == 1;
        deg2 += deg[i] == 2;
    }
    if (deg1 != 2 || deg2 != n - 2) {
        cout << "No";
        return 0;
    }
    vector<bool> visited(n, false);
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
    };
    dfs(0);
    cout << (count(visited.begin(), visited.end(), true) == n ? "Yes" : "No");
}
