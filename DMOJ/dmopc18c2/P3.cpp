/**
 *    author:  MaGnsi0
 *    created: 27.03.2023 23:03:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    function<vector<int>(int)> bfs = [&](int source) {
        vector<int> d(n, -1);
        queue<int> q;
        d[source] = 0; q.push(source);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& u : adj[v]) {
                if (d[u] != -1) { continue; }
                d[u] = d[v] + 1; q.push(u);
            }
        }
        return d;
    };
    vector<int> d1 = bfs(x - 1);
    vector<int> d2 = bfs(y - 1);
    int ans = 10 * n;
    for (int i = 0; i < k; ++i) {
        if (d1[a[i] - 1] == -1) { continue; }
        if (d2[a[i] - 1] == -1) { continue; }
        ans = min(ans, d1[a[i] - 1] + d2[a[i] - 1]);
    }
    cout << ans;
}
