/**
 *    author:  MaGnsi0
 *    created: 29.03.2023 21:33:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].emplace_back(v - 1, i);
        adj[v - 1].emplace_back(u - 1, i);
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    for (auto& [u, j] : adj[c]) {
        if (u == d) {
            cout << -1;
            return 0;
        }
    }
    vector<vector<int>> distance(n, vector<int>(3, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(3, {-1, -1}));
    queue<pair<int, int>> q;
    distance[a][0] = 0;
    q.emplace(a, 0);
    while (!q.empty()) {
        int v = q.front().first;
        int x = q.front().second;
        q.pop();
        if (v == b) { continue; }
        for (auto& [u, i] : adj[v]) {
            int y = x;
            if (u == c) { y |= 1; }
            if (u == d) { y |= 2; }
            if (y == 3) { continue; }
            if (distance[u][y] != -1) { continue; } 
            distance[u][y] = distance[v][x] + 1;
            q.emplace(u, y);
            parent[u][y] = make_pair(v, x);
        }
    }
    int v = -1, j = -1;
    for (int i = 0; i < 3; ++i) {
        if (distance[b][i] == -1) { continue; }
        if (v == -1 || distance[b][i] < distance[v][j]) {
            v = b, j = i;
        }
    }
    if (v == -1) {
        cout << -1;
        return 0;
    }
    int color_2 = (j == 2 ? c : d);
    vector<int> ans(m, 1);
    for (auto& [_, j] : adj[color_2]) {
        ans[j] = 2;
    }
    cout << 2 << "\n";
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
}
