/**
 *    author:  MaGnsi0
 *    created: 25.07.2023 18:14:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < k; ++i) {
            int x; cin >> x;
           a[x - 1] = 0;
        }
        vector<int> deg(n);
        vector<vector<int>> adj(n);
        for (int u = 0; u < n; ++u) {
            int m; cin >> m;
            for (int j = 0; j < m; ++j) {
                int v; cin >> v;
                adj[v - 1].push_back(u);
                deg[u]++;
            }
        }
        vector<int64_t> ans(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) {
                ans[i] = a[i];
                q.push(i);
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                deg[u]--;
                ans[u] += ans[v];
                if (deg[u] == 0) {
                    ans[u] = min(ans[u], a[u]);
                    q.push(u);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
