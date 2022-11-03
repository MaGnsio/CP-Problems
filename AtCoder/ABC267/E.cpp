/**
 *    author:  MaGnsi0
 *    created: 03.09.2022 13:58:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
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
    vector<int64_t> cur_val(n, 0);
    set<pair<int64_t, int>> op;
    vector<bool> erased(n, false);
    for (int i = 0; i < n; ++i) {
        for (auto& j : adj[i]) {
            cur_val[i] += a[j];
        }
        op.insert(make_pair(cur_val[i], i));
    }
    int64_t ans = 0;
    while (!op.empty()) {
        int v = op.begin() -> second;
        int64_t val = op.begin() -> first;
        op.erase(op.begin());
        for (auto& u : adj[v]) {
            if (erased[u]) {
                continue;
            }
            op.erase(make_pair(cur_val[u], u));
            cur_val[u] -= a[v];
            op.insert(make_pair(cur_val[u], u));
        }
        erased[v] = true;
        ans = max(ans, val);
    }
    cout << ans;
}
