/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 18:50:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int t; cin >> t;
    vector<int> d(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++, d[v]++;
    }
    function<vector<int>(int)> bfs = [&](int source) {
        queue<int> Q;
        vector<int> dis(n, -1);
        dis[source] = 0; Q.push(source);
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int u : adj[v]) {
                if (dis[u] != -1) { continue; }
                dis[u] = dis[v] + 1; Q.push(u);
            }
        }
        return dis;
    };
    vector<vector<int>> D;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 1) { D.push_back(bfs(i)); }
    }
    while (t--) {
        int v; cin >> v; v--;
        bool ron = (D[0][v] & 1) || (D[1][v] & 1);
        cout << (ron ? "Ron" : "Hermione") << "\n";
    }
}
