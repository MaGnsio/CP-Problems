/**
 *    author:  MaGnsi0
 *    created: 04.10.2023 16:34:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i]; c[i]--;
    }
    if (m == 1) {
        cout << "YES\n1";
        return 0;
    }
    vector<int> d(n), p(n);
    function<void(int, int)> dfs = [&](int v, int p_) {
        p[v] = p_;
        d[v] = (p_ == -1 ? 0 : d[p_] + 1);
        for (int u : adj[v]) {
            if (u == p_) { continue; }
            dfs(u, v);
        }
    };
    dfs(c[0], -1);
    for (int i = 2; i < m; ++i) {
        if (d[c[1]] < d[c[i]]) {
            swap(c[1], c[i]);
        }
    }
    if (d[c[1]] & 1) {
        cout << "NO";
        return 0;
    }
    int ans = -1;
    for (int u = c[1]; u != -1; u = p[u]) {
        if (d[u] == d[c[1]] / 2) {
            ans = u;
            break;
        }
    }
    dfs(ans, -1);
    for (int i = 0; i < m; ++i) {
        if (d[c[i]] != d[c[0]]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n" << ans + 1;
}
