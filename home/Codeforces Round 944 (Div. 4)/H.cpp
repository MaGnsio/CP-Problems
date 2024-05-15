/**
 *    author:  MaGnsi0
 *    created: 15.05.2024 20:06:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n = 3;
        int m; cin >> m;
        vector<vector<int>> a(n, vector<int>(m)); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector<bool> used(2 * m, false);
        vector<int> order, comp(2 * m, -1);
        vector<vector<int>> adj(2 * m), adj_t(2 * m);
        function<void(int, bool, int, bool)> add_disjunction = [&](int u, bool nu, int v, bool nv) {
            u = 2 * u ^ nu;
            v = 2 * v ^ nv;
            int neg_u = u ^ 1;
            int neg_v = v ^ 1;
            adj[neg_u].push_back(v);
            adj[neg_v].push_back(u);
            adj_t[v].push_back(neg_u);
            adj_t[u].push_back(neg_v);
        };
        function<void(int)> dfs1 = [&](int v) {
            used[v] = true;
            for (int u : adj[v]) {
                if (!used[u]) { dfs1(u); }
            }
            order.push_back(v);
        };
        function<void(int, int)> dfs2 = [&](int v, int cl) {
            comp[v] = cl;
            for (int u : adj_t[v]) {
                if (comp[u] == -1) { dfs2(u, cl); }
            }
        };
        for (int j = 0; j < m; ++j) {
            for (int i1 = 0; i1 < n; ++i1) {
                for (int i2 = i1 + 1; i2 < n; ++i2) {
                    int u = abs(a[i1][j]) - 1;
                    int v = abs(a[i2][j]) - 1;
                    add_disjunction(u, a[i1][j] < 0, v, a[i2][j] < 0);
                }
            }
        }
        for (int i = 0; i < 2 * m; ++i) {
            if (!used[i]) { dfs1(i); }
        }
        for (int i = 0, j = 0; i < 2 * m; ++i) {
            int v = order[2 * m - i - 1];
            if (comp[v] == -1) { dfs2(v, j++); }
        }
        bool can_win = true;
        for (int i = 0; i < 2 * m; i += 2) {
            can_win = can_win && comp[i] != comp[i + 1];
        }
        cout << (can_win ? "YES" : "NO") << "\n";
    }
}
