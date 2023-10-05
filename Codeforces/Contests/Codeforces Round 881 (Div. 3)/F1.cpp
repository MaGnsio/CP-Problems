/**
 *    author:  MaGnsi0
 *    created: 25.09.2023 04:26:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int Q; cin >> Q;
        int n = 1, m = 0;
        vector<int> a(n, 1);
        vector<vector<int>> adj(n);
        vector<vector<pair<int, int>>> b(n);
        while (Q--) {
            char t; cin >> t;
            if (t == '+') {
                int p; cin >> p; p--;
                int x; cin >> x;
                a.push_back(x);
                adj[p].push_back(n);
                adj.push_back({});
                b.push_back({});
                n++;
            } else {
                int u; cin >> u; u--;
                int v; cin >> v; v--;
                int k; cin >> k;
                assert(u == 0);
                b[v].push_back({k, m});
                m++;
            }
        }
        vector<bool> ans(m, false);
        function<void(int, int, int, int, int)> dfs = [&](int v, int max_sum, int cur_sum1, int min_sum, int cur_sum2) {
            cur_sum1 = max(cur_sum1 + a[v], 0);
            max_sum = max(max_sum, cur_sum1);
            cur_sum2 = min(cur_sum2 + a[v], 0);
            min_sum = min(min_sum, cur_sum2);
            for (auto [k, j] : b[v]) {
                ans[j] = ans[j] || (min_sum <= k && k <= max_sum);
            }
            for (int u : adj[v]) {
                dfs(u, max_sum, cur_sum1, min_sum, cur_sum2);
            }
        };
        dfs(0, 0, 0, 0, 0);
        for (int i = 0; i < m; ++i) {
            cout << (ans[i] ? "YES" : "NO") << "\n";
        }
    }
}
