/**
 *    author:  MaGnsi0
 *    created: 24.07.2022 16:34:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        if (m % 2 == 0) {
            cout << 0 << "\n";
            continue;
        }
        int ans = accumulate(a.begin(), a.end(), 0);
        vector<int> ok(n, false);
        for (int i = 0; i < n; ++i) {
            if ((int)adj[i].size() & 1) {
                ans = min(ans, a[i]);
            } else {
                ok[i] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if ((int)adj[i].size() & 1) {
                continue;
            }
            for (int j = 0; j < (int)adj[i].size(); ++j) {
                if ((int)adj[i].size() & 1) {
                    continue;
                }
                ans = min(ans, a[i] + a[adj[i][j]]);
            }
        }
        cout << ans << "\n";
    }
}
