/**
 *    author:  MaGnsi0
 *    created: 20.02.2023 15:40:57
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e17;

int n, m;
vector<vector<int>> adj;
vector<vector<int64_t>> capacity;

int64_t bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int64_t>> q;
    q.push({s, OO});
    while (!q.empty()) {
        int v = q.front().first;
        int64_t flow = q.front().second;
        q.pop();
        for (auto& u : adj[v]) {
            if (parent[u] == -1 && capacity[v][u]) {
                parent[u] = v;
                int64_t new_flow = min(flow, capacity[v][u]);
                if (u == t) {
                    return new_flow;
                }
                q.push({u, new_flow});
            }
        }
    }
    return 0;
}

int64_t max_flow(int s, int t) {
    int64_t flow = 0, new_flow;
    vector<int> parent(n);
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int v = t;
        while (v != s) {
            int u = parent[v];
            capacity[u][v] -= new_flow;
            capacity[v][u] += new_flow;
            v = u;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    capacity = vector<vector<int64_t>>(n, vector<int64_t>(n, 0));
    int s = 0, t = n - 1;
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        capacity[u - 1][v - 1] += x;
    }
    int64_t ans = max_flow(s, t);
    cout << ans << "\n";
}
