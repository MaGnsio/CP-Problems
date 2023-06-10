/**
 *    author:  MaGnsi0
 *    created: 28.05.2023 18:05:37
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
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].emplace_back(i, v - 1);
            adj[v - 1].emplace_back(i, u - 1);
        }
        vector<int> time(n, 1);
        function<void(int, int, int)> dfs = [&](int v, int p, int x) {
            for (auto [j, u] : adj[v]) {
                if (u == p) { continue; }
                time[u] = time[v] + (j < x);
                dfs(u, v, j);
            }
        };
        dfs(0, -1, -1);
        int ans = *max_element(time.begin(), time.end());
        cout << ans << "\n";
    }
}
