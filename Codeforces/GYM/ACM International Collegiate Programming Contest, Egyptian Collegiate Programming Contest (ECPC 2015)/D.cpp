/**
 *    author:  MaGnsi0
 *    created: 20.06.2023 16:36:55
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
        vector<vector<pair<int, int64_t>>> adj(n);
        for (int v = 2; v <= n; ++v) {
            int u, w;
            cin >> u >> w;
            adj[u - 1].emplace_back(v - 1, w);
        }
        vector<int64_t> ans(n, 0);
        vector<bool> is_leaf(n, false);
        function<void(int, int)> dfs = [&](int v, int p) {
            int64_t min_edge = INT64_MAX;
            for (auto [u, w] : adj[v]) {
                if (u == p) { continue; }
                min_edge = min(min_edge, w);
            }
            if (min_edge == INT64_MAX) {
                is_leaf[v] = true;
            }
            for (auto [u, w] : adj[v]) {
                if (u == p) { continue; }
                ans[u] = ans[v] + min_edge + 2 * (w - min_edge);
                dfs(u, v);
            }
        };
        dfs(0, -1);
        vector<int64_t> ans_leaf;
        for (int i = 0; i < n; ++i) {
            if (is_leaf[i]) {
                ans_leaf.push_back(ans[i]);
            }
        }
        sort(ans_leaf.begin(), ans_leaf.end());
        int Q, m = (int)ans_leaf.size();
        cin >> Q;
        while (Q--) {
            int64_t t;
            cin >> t;
            int ans = upper_bound(ans_leaf.begin(), ans_leaf.end(), t) - ans_leaf.begin();
            cout << ans << "\n";
        }
    }
}
