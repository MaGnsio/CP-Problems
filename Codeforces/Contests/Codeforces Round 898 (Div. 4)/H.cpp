/**
 *    author:  MaGnsi0
 *    created: 19.12.2024 23:13:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a; cin >> a; a--;
        int b; cin >> b; b--;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> cycle;
        {
            int s = -1, e = -1;
            vector<bool> visited(n, false);
            vector<int> parent(n, -1);
            function<bool(int, int)> dfs = [&](int v, int p) {
                visited[v] = true;
                for (int u : adj[v]) {
                    if (u == p) { continue; }
                    if (visited[u]) {
                        s = u, e = v;
                        return true;
                    }
                    parent[u] = v;
                    if (dfs(u, v)) { return true; }
                }
                return false;
            };
            dfs(0, -1);
            cycle.push_back(s);
            for (int v = e; v != s; v = parent[v]) {
                cycle.push_back(v);
            }
        }
        vector<int> dis_a(n, INT_MAX), dis_b(n, INT_MAX);
        {
            queue<int> Q;
            dis_a[a] = 0; Q.push(a);
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                for (int u : adj[v]) {
                    if (dis_a[v] + 1 < dis_a[u]) {
                        dis_a[u] = dis_a[v] + 1; Q.push(u);
                    }
                }
            }
        }
        {
            queue<int> Q;
            dis_b[b] = 0; Q.push(b);
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                for (int u : adj[v]) {
                    if (dis_b[v] + 1 < dis_b[u]) {
                        dis_b[u] = dis_b[v] + 1; Q.push(u);
                    }
                }
            }
        }
        bool ok = false;
        for (int v : cycle) {
            ok = ok || (dis_a[v] > dis_b[v]);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
