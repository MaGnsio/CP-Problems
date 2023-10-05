/**
 *    author:  MaGnsi0
 *    created: 20.02.2023 18:18:33
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;

int n, m;
vector<int> a, b;
vector<vector<int>> adj, capacity, flows;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    parent[s] = -2;
    q.push({s, OO});
    while (!q.empty()) {
        int v = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int u : adj[v]) {
            if (parent[u] == -1 && capacity[v][u]) {
                parent[u] = v;
                int new_flow = min(flow, capacity[v][u]);
                if (u == t) {
                    return flow;
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
    while(new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int v = t;
        while (v != s) {
            int u = parent[v];
            capacity[u][v] -= new_flow;
            capacity[v][u] += new_flow;
            flows[u][v] += new_flow;
            flows[v][u] -= new_flow;
            v = u;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a = b = vector<int>(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    int s = 0, t = n + 1;
    adj = vector<vector<int>>(2 * (n + 2));
    capacity = flows = vector<vector<int>>(2 * (n + 2), vector<int>(2 * (n + 2), 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v + n + 2);
        adj[v + n + 2].push_back(u);
        adj[v].push_back(u + n + 2);
        adj[u + n + 2].push_back(v);
        capacity[u][v + n + 2] = OO;
        capacity[v][u + n + 2] = OO;
    }
    for (int i = 1; i <= n; ++i) {
        adj[i].push_back(i + n + 2);
        adj[i + n + 2].push_back(i);
        capacity[i][i + n + 2] = OO;
        adj[s + n + 2].push_back(i);
        adj[i].push_back(s + n + 2);
        capacity[s + n + 2][i] = a[i];
        adj[i + n + 2].push_back(t);
        adj[t].push_back(i + n + 2);
        capacity[i + n + 2][t] = b[i];
    }
    adj[s].push_back(s + n + 2);
    adj[s + n + 2].push_back(s);
    capacity[s][s + n + 2] = OO;
    adj[t].push_back(t + n + 2);
    adj[t + n + 2].push_back(t);
    capacity[t][t + n + 2] = OO;
    int sum_a = accumulate(a.begin(), a.end(), 0);
    int sum_b = accumulate(b.begin(), b.end(), 0);
    int ans = max_flow(s, t + n + 2);
    if (sum_a != sum_b || sum_a != ans) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << flows[i][j + n + 2] << " ";
            }
            cout << "\n";
        }
    }
}
