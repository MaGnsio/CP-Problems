/**
 *    author:  MaGnsi0
 *    created: 30.07.2024 17:53:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int v = 1; v < n; ++v) {
            int u; cin >> u; u--;
            adj[u].push_back(v);
        }
        function<bool(int, int64_t)> dfs = [&](int v, int64_t need) {
            if (need > int64_t(1e9)) {
                return false;
            }
            if (adj[v].empty()) {
                return a[v] >= need;
            }
            bool ok = true;
            for (int u : adj[v]) {
                ok = ok && dfs(u, need + max(need - a[u], 0LL));
            }
            return ok;
        };
        int64_t low = a[0], high = 1e15, ans = a[0];
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if (dfs(0, mid - a[0])) {
                ans = mid, low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
