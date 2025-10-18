/**
 *    author:  MaGnsi0
 *    created: 18.10.2025 20:21:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n; n++;
        vector<int> a(n);
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
        }
        vector<tuple<int, int, int64_t>> edges;
        for (int i = 1; i < n; ++i) {
            edges.emplace_back(0, i, a[i]);
            if (i > 1) {
                edges.emplace_back(i - 1, i, abs(a[i] - a[i - 1]));
            }
        }
        function<bool(int64_t)> ok = [&](int64_t x) {
            vector<vector<int>> adj(n);
            for (auto [u, v, w] : edges) {
                if (w <= x) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
            int m = 0;
            {
                queue<int> Q;
                vector<bool> visited(n, false);
                Q.push(0); visited[0] = true;
                while (!Q.empty()) {
                    int v = Q.front(); Q.pop(); m++;
                    for (int u : adj[v]) {
                        if (!visited[u]) {
                            Q.push(u); visited[u] = true;
                        }
                    }
                }
            }
            return n == m;
        };
        int64_t low = 0, high = 2e9, ans = high;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if (ok(mid)) {
                ans = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
