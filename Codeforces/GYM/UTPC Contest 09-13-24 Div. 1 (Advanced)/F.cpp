/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 19:50:56
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, s, k, g;
    cin >> n >> m >> s >> k >> g; s--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> a(k), b(g);
    for (int i = 0; i < k; ++i) {
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < g; ++i) {
        cin >> b[i]; b[i]--;
    }
    function<vector<int>(vector<int>)> bfs = [&](vector<int> S) {
        queue<int> Q;
        vector<int> d(n, OO);
        for (int v : S) {
            Q.push(v); d[v] = 0;
        }
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int u : adj[v]) {
                if (d[v] + 1 < d[u]) {
                    Q.push(u); d[u] = d[v] + 1;
                }
            }
        }
        return d;
    };
    int ans = 0;
    vector<int> d1 = bfs(b), d2 = bfs({s});
    for (int e : a) {
        ans += d1[e] > d2[e];
    }
    cout << ans;
}
