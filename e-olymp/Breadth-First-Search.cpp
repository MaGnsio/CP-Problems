/**
 *    author:  MaGnsi0
 *    created: 08/06/2021 00:56:24
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, s, e;
    cin >> n >> s >> e;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (x) {
                adj[i].push_back(j);
            }
        }
    }
    vector<bool> visited(n + 1, false);
    vector<int> d(n + 1, 0);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
    cout << d[e];
}
