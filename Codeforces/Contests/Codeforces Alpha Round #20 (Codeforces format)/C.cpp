/**
 *    author:  MaGnsi0
 *    created: 19.02.2022 19:07:57
**/
#include <bits/stdc++.h>

using namespace std;

const long long OO = 1e12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }
    vector<long long> d(n, OO), p(n, -1);
    using pli = pair<long long, int>;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    d[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int v = q.top().second;
        long long d_v = q.top().first;
        q.pop();
        if (d[v] != d_v) {
            continue;
        }
        for (auto& [u, w] : adj[v]) {
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                p[u] = v;
                q.push({d[u], u});
            }
        }
    }
    if (d[n - 1] == OO) {
        cout << -1;
    } else {
        vector<int> path;
        for (int u = n - 1; u != -1; u = p[u]) {
            path.push_back(u + 1);
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < (int)path.size(); ++i) {
            cout << path[i] << " ";
        }
    }
}
