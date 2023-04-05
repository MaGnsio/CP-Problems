/**
 *    author:  MaGnsi0
 *    created: 20.02.2023 16:07:24
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;

int N, M, X;
vector<int> a, b, c;
vector<vector<int>> adj, capacity;

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
    vector<int> parent(N);
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int v = t;
        while (v != s) {
            int u = parent[v];
            capacity[u][v] -= new_flow;
            capacity[v][u] += new_flow;
            v = u;
        }
        if (flow >= X) {
            return flow;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> X;
    a = b = c = vector<int>(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }
    double low = 0.00001, high = 1e6;
    for (int _ = 0; _ < 300; ++_) {
        double mid = (low + high) / 2.0;
        adj = vector<vector<int>>(N);
        capacity = vector<vector<int>>(N, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
            capacity[a[i]][b[i]] = c[i] / mid;
        }
        if (max_flow(0, N - 1) >= X) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << fixed << setprecision(6) << low * X;
}
