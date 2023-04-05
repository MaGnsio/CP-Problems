/**
 *    author:  MaGnsi0
 *    created: 20.02.2023 15:04:20
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 100000;

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
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        adj = vector<vector<int>>(n, vector<int>(0));
        capacity = vector<vector<int>>(n, vector<int>(n, 0));
        int s = 0, t = n - 1;
        for (int u = 0; u < n - 1; ++u) {
            int k;
            cin >> k;
            for (int i = 0; i < k; ++i) {
                int v;
                cin >> v;
                adj[u].push_back(v - 1);
                adj[v - 1].push_back(u);
                if (u == 0 || v == n) {
                    capacity[u][v - 1] = 1;
                } else {
                    capacity[u][v - 1] = OO;
                }
            }
        }
        int ans = max_flow(s, t);
        cout << ans << "\n";
    }
}
