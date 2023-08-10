/**
 *    author:  MaGnsi0
 *    created: 22.04.2023 22:41:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) { 
        int u, v, d;
        cin >> u >> v >> d;
        adj[u - 1].emplace_back(v - 1, d);
        adj[v - 1].emplace_back(u - 1, d);
    }
    vector<bool> good(n, true);
    for (int v = 0; v < n; ++v) {
        for (auto [u, d] : adj[v]) {
            good[v] = good[v] && (d == 1);
        }
    }
    vector<int> b(n, 0);
    for (int v = 0; v < n; ++v) {
        for (auto [u, d] : adj[v]) {
            b[v] = max(b[v], d);
        }
    }
    set<int> ans;
    function<void(int)> solve = [&](int source) {
        vector<vector<int>> ok(n, vector<int>(k + 1, -1));
        queue<pair<int, int>> q;
        ok[source][0] = 1;
        q.emplace(source, 0);
        while (!q.empty()) {
            int v = q.front().first;
            int d_old = q.front().second;
            q.pop();
            for (auto [u, d] : adj[v]) {
                if (d != d_old + 1) { continue; }
                if (ok[u][d] != -1) { continue; }
                if (b[u] > d + 1) { continue; }
                ok[u][d] = 1;
                q.emplace(u, d);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ok[i][k] == 1) {
                ans.insert(i);
            }
        }
    };
    for (int v = 0; v < n; ++v) {
        if (good[v]) {
            solve(v);
        }
    }
    cout << (int)ans.size() << "\n";
    for (int v : ans) {
        cout << v + 1 << "\n";
    }
}
