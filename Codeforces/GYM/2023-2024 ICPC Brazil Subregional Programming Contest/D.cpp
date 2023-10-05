/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 22:16:03
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 5e8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> U(m), V(m), W(m);
    for (int i = 0; i < m; ++i) {
        cin >> U[i]; U[i]--;
        cin >> V[i]; V[i]--;
        cin >> W[i];
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        adj[U[i]].emplace_back(V[i], W[i]);
        adj[V[i]].emplace_back(U[i], W[i]);
    }
    vector<vector<int>> ans(n, vector<int>(n, OO));
    for (int source = 0; source < n; ++source) {
        vector<pair<int, int>> a(n, {OO, -1});
        vector<pair<int, int>> b(n, {OO, -1});
        set<tuple<int, int, int>> s;
        for (auto [u, w] : adj[source]) {
            a[u] = {w, u};
            s.emplace(a[u].first, u, u);
        }
        while (!s.empty()) {
            int v = get<1>(*s.begin());
            int d_v = get<0>(*s.begin());
            int k = get<2>(*s.begin());
            s.erase(s.begin());
            if (d_v != a[v].first && d_v != b[v].first) { continue; }
            for (auto [u, w] : adj[v]) {
                if (u == source) { continue; }
                if (d_v + w < a[u].first) {
                    if (a[u].second != k) {
                        b[u].first = a[u].first;
                    }
                    a[u] = {d_v + w, k};
                    s.emplace(a[u].first, u, k);
                } else if (a[u].second != k && d_v + w < b[u].first) {
                    b[u] = {d_v + w, k};
                    s.emplace(b[u].first, u, k);
                }
            }
        }
        for (int u = 0; u < n; ++u) {
            if (a[u].second == u) {
                ans[source][u] = b[u].first;
            } else {
                ans[source][u] = a[u].first;
            }
            ans[source][u] = (ans[source][u] == OO ? -1 : ans[source][u]);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[U[i]][V[i]] << "\n"; 
    }
}
