/**
 *    author:  MaGnsi0
 *    created: 09.02.2025 17:43:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string ans(n, '0');
        for (int i = 0; i < n; ++i) {
            map<int, int> mp; mp[a[i]]++;
            for (int j : adj[i]) { mp[a[j]]++; }
            for (auto [x, y] : mp) {
                if (y >= 2) { ans[x - 1] = '1'; }
            }
        }
        cout << ans << "\n";
    }
}
