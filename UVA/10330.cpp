/**
 *    author:  MaGnsi0
 *    created: 20.02.2023 13:50:23
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = INT_MAX;

int n;
vector<vector<int>> adj;
vector<vector<int>> capacity;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, OO});
    while (!q.empty()) {
        int v = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (auto& u : adj[v]) {
            if (parent[u] == -1 && capacity[v][u]) {
                parent[u] = v;
                int new_flow = min(flow, capacity[v][u]);
                if (u == t) {
                    return new_flow;
                }
                q.push({u, new_flow});
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0, new_flow;
    vector<int> parent(2 * (n + 2));
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
    while (cin >> n) {
        adj = vector<vector<int>>(2 * (n + 2));
        capacity = vector<vector<int>>(2 * (n + 2), vector<int>(2 * (n + 2), 0));
        int s = 0, t = n + 1;
        adj[s].push_back(s + n + 2);
        capacity[s][s + n + 2] = OO;
        adj[t].push_back(t + n + 2);
        capacity[t][t + n + 2] = OO;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            adj[i].push_back(i + n + 2);
            adj[i + n + 2].push_back(i);
            capacity[i][i + n + 2] = x;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            int x;
            cin >> u >> v >> x;
            adj[u + n + 2].push_back(v);
            adj[v].push_back(u + n + 2);
            capacity[u + n + 2][v] += x;
        }
        int k1, k2;
        cin >> k1 >> k2;
        for (int i = 0; i < k1; ++i) {
            int v;
            cin >> v;
            adj[s + n + 2].push_back(v);
            adj[v].push_back(s + n + 2);
            capacity[s + n + 2][v] = OO;
        }
        for (int i = 0; i < k2; ++i) {
            int v;
            cin >> v;
            adj[v + n + 2].push_back(t);
            adj[t].push_back(s + n + 2);
            capacity[v + n + 2][t] = OO;
        }
        int ans = max_flow(s, t + n + 2);
        cout << ans << endl;
    }
}
