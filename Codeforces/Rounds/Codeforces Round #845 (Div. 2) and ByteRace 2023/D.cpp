/**
 *    author:  MaGnsi0
 *    created: 21.01.2023 17:51:04
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> P2(N, 1);
    for (int i = 1; i < N; ++i) {
        P2[i] = 2 * P2[i - 1];
        P2[i] %= MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        vector<int> h(n);
        function<int(int, int, int)> dfs = [&](int v, int p, int cur_h) {
            int max_h = cur_h;
            for (auto& u : adj[v]) {
                if (u == p) { continue; }
                max_h = max(max_h, dfs(u, v, cur_h + 1));
            }
            h[v] = max_h - cur_h + 1;
            return max_h;
        };
        dfs(0, -1, 0);
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += h[i] * P2[n - 1];
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
