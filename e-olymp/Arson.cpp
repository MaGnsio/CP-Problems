/**
 *    author:  MaGnsi0
 *    created: 08/06/2021 18:37:03
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    vector<int> t(n + 1, 0);
    queue<int> q;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        visited[v] = true;
        q.push(v);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                t[u] = t[v] + 1;
            }
        }
    }
    int x = *max_element(t.begin() + 1, t.end()), y = max_element(t.begin() + 1, t.end()) - t.begin();
    cout << x << "\n" << y;
}
