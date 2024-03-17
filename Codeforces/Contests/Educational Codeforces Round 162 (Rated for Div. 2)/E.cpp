/**
 *    author:  MaGnsi0
 *    created: 28.02.2024 21:38:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> color(n);
        for (int i = 0; i < n; ++i) {
            cin >> color[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int64_t ans = 0;
        vector<map<int, int64_t>> colors(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            int big = -1;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
                if (colors[u].count(color[v])) {
                    ans += colors[u][color[v]];
                }
                if (big == -1 || (int)colors[big].size() < (int)colors[u].size()) {
                    big = u;
                }
            }
            if (big == -1) {
                colors[v][color[v]] = 1;
                return;
            }
            swap(colors[v], colors[big]);
            for (int u : adj[v]) {
                if (u == p || u == big) { continue; }
                for (auto [c, x] : colors[u]) {
                    if (c != color[v]) {
                        ans += colors[v][c] * x;
                    }
                    colors[v][c] += x;
                }
            }
            colors[v][color[v]] = 1;
        };
        dfs(0, -1);
        cout << ans << "\n";
    }
}
