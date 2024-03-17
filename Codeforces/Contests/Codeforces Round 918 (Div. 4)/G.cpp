/**
 *    author:  MaGnsi0
 *    created: 28.12.2023 18:33:38
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = INT64_MAX;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<vector<pair<int, int64_t>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            int w; cin >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<tuple<int64_t, int, int>> s;
        vector<vector<int64_t>> ans(n, vector<int64_t>(n, OO));
        ans[0][0] = 0;
        s.emplace(0, 0, 0);
        while (!s.empty()) {
            auto [dv, v, p] = *s.begin();
            s.erase(s.begin());
            if (ans[v][p] != dv) { continue; }
            for (auto [u, w] : adj[v]) {
                int new_p = (a[p] < a[v] ? p : v); 
                int64_t new_ans = ans[v][p] + a[new_p] * w;
                if (new_ans < ans[u][new_p]) {
                    ans[u][new_p] = new_ans;
                    s.emplace(new_ans, u, new_p);
                }
            }
        }
        int64_t best = *min_element(ans[n - 1].begin(), ans[n - 1].end());
        cout << best << "\n";
    }
}
