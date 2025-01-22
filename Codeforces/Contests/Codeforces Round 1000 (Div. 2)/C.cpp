/**
 *    author:  MaGnsi0
 *    created: 22.01.2025 17:45:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u; cin >> u; u--;
            int v; cin >> v; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> F(n), FC(n);
        for (int i = 0; i < n; ++i) {
            F[i] = (int)adj[i].size();
            FC[F[i]]++;
        }
        set<int> S(F.begin(), F.end());
        function<void(int, int)> update = [&](int v, int c) {
            FC[F[v]] += c;
            if (FC[F[v]] == 0) {
                S.erase(F[v]);
            } else {
                S.insert(F[v]);
            }
        };
        int ans = 0;
        for (int u = 0; u < n; ++u) {
            update(u, -1);
            for (int v : adj[u]) {
                update(v, -1);
            }
            if (!S.empty()) {
                ans = max(ans, F[u] + *S.rbegin() - 1);
            }
            for (int v : adj[u]) {
                ans = max(ans, F[u] + F[v] - 2);
            }
            update(u, +1);
            for (int v : adj[u]) {
                update(v, +1);
            }
        }
        cout << ans << "\n";
    }
}
