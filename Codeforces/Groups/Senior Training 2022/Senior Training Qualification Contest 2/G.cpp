/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 20:49:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("akrik.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n);
        for (int u = 1, v; u < n; ++u) {
            cin >> v;
            adj[u].push_back(v - 1);
            adj[v - 1].push_back(u);
        }
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long ans = 0;
        vector<bool> visited(n, false);
        function<long long(int)> solve = [&](int v) {
            visited[v] = true;
            long long cnt = a[v];
            for (auto& u : adj[v]) {
                if (!visited[u]) {
                    cnt += solve(u);
                }
            }
            if (v) {
                ans += (cnt % k);
            }
            return cnt;
        };
        solve(0);
        cout << ans << "\n";
    }
}
