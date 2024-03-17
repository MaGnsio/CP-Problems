/**
 *    author:  MaGnsi0
 *    created: 16.02.2024 19:43:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; a[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[v].push_back(u);
    }
    for (int p = 0; p < n; ++p) {
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) {
            for (int j : adj[i]) {
                deg[j]++;
            }
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            if (deg[i] || i == p) { continue; }
            q.emplace(a[i], i);
        }
        int ans = n - 1;
        while (!q.empty()) {
            int v = q.top().second;
            q.pop();
            if (a[v] < ans) {
                assert(deg[p] == 0 && a[p] >= ans);
                break;
            }
            ans--;
            for (int u : adj[v]) {
                deg[u]--;
                if (deg[u] == 0 && u != p) {
                    q.emplace(a[u], u);
                }
            }
        }
        cout << ans + 1 << " ";
    }
}
