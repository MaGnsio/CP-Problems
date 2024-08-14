/**
 *    author:  MaGnsi0
 *    created: 14.08.2024 21:17:26
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 2e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int64_t t1; cin >> t1;
        int64_t t2; cin >> t2;
        int64_t t3; cin >> t3;
        vector<vector<tuple<int, int64_t, int64_t>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            int64_t tb; cin >> tb;
            int64_t tw; cin >> tw;
            adj[u].emplace_back(v, tb, tw);
            adj[v].emplace_back(u, tb, tw);
        }
        function<bool(int)> F = [&](int64_t t0) {
            vector<int64_t> d(n, OO);
            set<pair<int64_t, int>> S;
            d[0] = t0; S.emplace(t0, 0);
            while (!S.empty()) {
                auto [d_v, v] = *S.begin();
                S.erase(S.begin());
                if (d_v != d[v]) { continue; }
                for (auto [u, tb, tw] : adj[v]) {
                    if (d[v] + tb <= t2 || t3 <= d[v]) {
                        if (d[v] + tb < d[u]) {
                            d[u] = d[v] + tb;
                            S.emplace(d[u], u);
                        }
                    } else {
                        if (min(d[v] + tw, t3 + tb) < d[u]) {
                            d[u] = min(d[v] + tw, t3 + tb);
                            S.emplace(d[u], u);
                        }
                    }
                }
            }
            return d[n - 1] <= t1;
        };
        int64_t low = 0, high = t1, ans = -1;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
