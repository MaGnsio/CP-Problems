/**
 *    author:  MaGnsi0
 *    created: 20.06.2023 16:54:32
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, m, k;
        cin >> n >> m >> k;
        vector<vector<tuple<int, int64_t, int64_t>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int64_t u, v, c, w;
            cin >> u >> v >> c >> w;
            adj[u - 1].emplace_back(v - 1, c, w);
            adj[v - 1].emplace_back(u - 1, c, w);
        }
        function<bool(int64_t)> F = [&](int64_t x) {
            vector<int64_t> d(n, OO);
            set<pair<int64_t, int64_t>> s;
            d[0] = 0, s.emplace(0, 0);
            while (!s.empty()) {
                int v = s.begin() -> second;
                s.erase(s.begin());
                for (auto [u, c, w] : adj[v]) {
                    if (w > x) { continue; }
                    if (d[v] + c < d[u]) {
                        d[u] = d[v] + c;
                        s.emplace(d[u], u);
                    }
                }
            }
            return d[n - 1] < k;
        };
        int64_t low = 1, high = 1e15, ans = -1;
        while (low <= high) {
            int64_t mid = (low + high) / 2;;
            if (F(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
