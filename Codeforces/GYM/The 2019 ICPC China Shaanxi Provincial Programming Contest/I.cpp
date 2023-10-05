/**
 *    author:  MaGnsi0
 *    created: 15.09.2023 18:53:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<pair<int, char>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            char c; cin >> c;
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
        }
        vector<bool> good(n, true);
        vector<vector<int>> F(n, vector<int>(26, 0));
        function<void(int, int)> dfs = [&](int v, int p) {
            for (auto [u, c] : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
                good[v] = good[v] && good[u];
                F[v][c - 'a']++;
                good[v] = good[v] && (F[v][c - 'a'] < 2);
            }
        };
        dfs(0, -1);
        int ans = 0;
        function<void(int, int)> solve = [&](int v, int p) {
            ans += good[v];
            int m = (int)adj[v].size();
            vector<bool> P(m), S(m);
            for (int i = 0; i < m; ++i) {
                int u = adj[v][i].first;
                P[i] = good[u] && (i ? P[i - 1] : true);
            }
            for (int i = m - 1; i >= 0; --i) {
                int u = adj[v][i].first;
                S[i] = good[u] && (i + 1 < m ? S[i + 1] : true);
            }
            for (int i = 0; i < m; ++i) {
                int u = adj[v][i].first;
                char c = adj[v][i].second;
                if (u == p) { continue; }
                bool goodv = good[v];
                bool goodu = good[u];
                F[v][c - 'a']--, F[u][c - 'a']++;
                good[v] = (i ? P[i - 1] : true) && (i + 1 < m ? S[i + 1] : true);
                for (int j = 0; j < 26; ++j) {
                    good[v] = good[v] && (F[v][j] < 2);
                }
                good[u] = goodu && good[v] && (F[u][c - 'a'] < 2);
                solve(u, v);
                good[v] = goodv, good[u] = goodu;
                F[v][c - 'a']++, F[u][c - 'a']--;
            }
        };
        solve(0, -1);
        cout << ans << "\n";
    }
}
