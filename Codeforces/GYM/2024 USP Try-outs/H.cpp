/**
 *    author:  MaGnsi0
 *    created: 24.08.2024 11:33:06
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int t; cin >> t;
    vector<vector<tuple<int, int64_t, int64_t>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        int64_t x; cin >> x;
        int64_t y; cin >> y;
        adj[u].emplace_back(v, x, y);
        adj[v].emplace_back(u, x, y);
    }
    set<pair<int64_t, int>> S;
    vector<int64_t> ans(n, OO);
    ans[0] = t; S.emplace(ans[0], 0);
    while (!S.empty()) {
        auto [ans_v, v] = *S.begin();
        S.erase(S.begin());
        if (ans_v != ans[v]) { continue; }
        for (auto [u, x, y] : adj[v]) {
            int64_t s = ans[v] % (x + y);
            int64_t t = (s < x ? ans[v] : ans[v] + x + y - s);
            if (t < ans[u]) {
                ans[u] = t; S.emplace(ans[u], u);
            }
        }
    }
    cout << ans[n - 1];
}
