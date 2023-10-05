/**
 *    author:  MaGnsi0
 *    created: 25.09.2023 19:17:01
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 21;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        vector<int64_t> size_(n);
        vector<vector<int64_t>> O(n, vector<int64_t>(M));
        vector<vector<int64_t>> Z(n, vector<int64_t>(M));
        function<void(int, int)> dfs = [&](int v, int p) {
            size_[v] = 1;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v);
                size_[v] += size_[u];
                for (int i = 0; i < M; ++i) {
                    if (a[v] >> i & 1) {
                        O[v][i] += O[u][i];
                        Z[v][i] += O[u][i];
                    } else {
                        O[v][i] += Z[u][i];
                        Z[v][i] += Z[u][i];
                    }
                }
            }
            for (int i = 0; i < M; ++i) {
                if (a[v] >> i & 1) {
                    Z[v][i] += size_[v];
                } else {
                    O[v][i] += size_[v];
                }
            }
        };
        dfs(0, -1);
        vector<int64_t> ans(n, 0);
        function<void(int, int)> solve = [&](int v, int p) {
            for (int i = 0; i < M; ++i) {
                ans[v] += 1LL * min(O[v][i], Z[v][i]) * (1LL << i);
            }
            for (int u : adj[v]) {
                if (u == p) { continue; }
                int64_t Sv = size_[v], Su = size_[u];
                vector<int64_t> Ov = O[v], Ou = O[u];
                vector<int64_t> Zv = Z[v], Zu = Z[u];
                size_[v] = size_[v] - size_[u], size_[u] = n;
                for (int i = 0; i < M; ++i) {
                    if (a[v] >> i & 1) {
                        Z[v][i] -= Sv;
                        O[v][i] -= O[u][i];
                        Z[v][i] -= O[u][i];
                        Z[v][i] += size_[v];
                    } else {
                        O[v][i] -= Sv;
                        O[v][i] -= Z[u][i];
                        Z[v][i] -= Z[u][i];
                        O[v][i] += size_[v];
                    }
                    if (a[u] >> i & 1) {
                        Z[u][i] -= Su;
                        O[u][i] += O[v][i];
                        Z[u][i] += O[v][i];
                        Z[u][i] += size_[u];
                    } else {
                        O[u][i] -= Su;
                        O[u][i] += Z[v][i];
                        Z[u][i] += Z[v][i];
                        O[u][i] += size_[u];
                    }
                }
                solve(u, v);
                size_[v] = Sv, size_[u] = Su;
                O[v] = Ov, O[u] = Ou;
                Z[v] = Zv, Z[u] = Zu;
            }
        };
        solve(0, -1);
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
