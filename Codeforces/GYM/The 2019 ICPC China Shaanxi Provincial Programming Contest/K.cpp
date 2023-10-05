/**
 *    author:  MaGnsi0
 *    created: 16.09.2023 07:53:08
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = INT_MAX;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i]; a[i]--;
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u - 1].emplace_back(v - 1, w);
            adj[v - 1].emplace_back(u - 1, w);
        }
        vector<int> d(n, OO);
        multiset<pair<int, int>> s;
        for (int i = 0; i < k; ++i) {
            b[a[i]] = 0;
            s.emplace(0, a[i]);
        }
        while (!s.empty()) {
            int v = s.begin() -> second;
            int d_v = s.begin() -> first;
            s.erase(s.begin());
            if (b[v]-- > 0) { continue; }
            if (d[v] != OO) { continue; }
            d[v] = d_v;
            for (auto [u, w] : adj[v]) {
                if (d[u] != OO) { continue; }
                if (d[v] + w < d[u]) {
                    s.emplace(d[v] + w, u);
                }
            }
        }
        cout << (d[0] == OO ? -1 : d[0]) << "\n";
    }
}
