/**
 *    author:  MaGnsi0
 *    created: 13.03.2023 23:39:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(2 * n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        char cu, cv;
        cin >> u >> cu >> v >> cv;
        u += (cu == 'B') * n;
        v += (cv == 'B') * n;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; ++i) {
        adj[i].push_back(i + n);
        adj[i + n].push_back(i);
    }
    int cycles = 0, not_cycles = 0;
    vector<bool> visited(2 * n, false);
    function<bool(int, int)> dfs = [&](int v, int p) {
        visited[v] = true;
        bool have_cycle = false;
        for (auto& u : adj[v]) {
            if (visited[u] && u != p) {
                have_cycle = true;
            } else if (visited[u] == false) {
                have_cycle |= dfs(u, v);
            }
        }
        return have_cycle;
    };
    for (int i = 0; i < 2 * n; ++i) {
        if (visited[i] == false) {
            if (dfs(i, -1)) {
                cycles++;
            } else {
                not_cycles++;
            }
        }
    }
    cout << cycles << " " << not_cycles;
}
