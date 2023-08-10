#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> in_deg(n), deg(n), U(m), V(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        cin >> U[i] >> V[i];
        deg[U[i]]++, deg[V[i]]++;
    }
    for (int i = 0; i < m; ++i) {
        int u = U[i], v = V[i];
        if (deg[u] < deg[v]) {
            in_deg[v]++;
            adj[u].push_back(v);
        } else if (deg[u] > deg[v]) {
            in_deg[u]++;
            adj[v].push_back(u);
        }
    }
    vector<int> d(n, OO);
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            d[i] = -1;
            s.emplace(-1, i);
        }
    }
    while (!s.empty()) {
        int d_v = s.begin() -> first;
        int v = s.begin() -> second;
        s.erase(s.begin());
        if (d[v] != d_v) { continue; }
        for (int u : adj[v]) {
            if (d[v] - 1 < d[u]) {
                d[u] = d[v] - 1;
                s.emplace(d[u], u);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, -d[i]);
    }
    cout << ans;
}
