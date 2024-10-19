/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 15:21:41
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u;
        int v; cin >> v;
        adj[u - 1].push_back(v - 1);
    }
    vector<int> d(n, OO);
    queue<int> Q;
    d[0] = 0; Q.push(0);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int u : adj[v]) {
            if (d[v] + 1 < d[u]) {
                d[u] = d[v] + 1; Q.push(u);
            }
        }
    }
    int ans = OO;
    for (int i = 1; i < n; ++i) {
        if (d[i] == OO) { continue; }
        for (int j : adj[i]) {
            if (j == 0) {
                ans = min(ans, d[i] + 1);
            }
        }
    }
    cout << (ans == OO ? -1 : ans);
}
