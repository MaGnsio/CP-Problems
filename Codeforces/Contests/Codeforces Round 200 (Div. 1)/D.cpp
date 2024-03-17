/**
 *    author:  MaGnsi0
 *    created: 05.12.2023 14:50:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dfs_time = 0;
    vector<int> tin(n), tout(n), p(n, -1);
    function<void(int)> dfs = [&](int v) {
        tin[v] = dfs_time++;
        for (int u : adj[v]) {
            if (u == p[v]) { continue; }
            p[u] = v;
            dfs(u);
        }
        tout[v] = dfs_time++;
    };
    vector<int> T(8 * n, 1), L(8 * n, -1);
    function<void(int)> push = [&](int j) {
        if (L[j] == -1) { return; }
        T[2 * j + 1] = L[j];
        L[2 * j + 1] = L[j];
        T[2 * j + 2] = L[j];
        L[2 * j + 2] = L[j];
        L[j] = -1;
    };
    function<void(int, int, int, int, int, int)> update = [&](int j, int low, int high, int from, int to, int x) {
        if (low > high) { return; }
        if (to < low || high < from) { return; }
        if (from <= low && high <= to) {
            T[j] = L[j] = x;
            return;
        }
        push(j);
        int mid = (low + high) / 2;
        update(2 * j + 1, low, mid, from, to, x);
        update(2 * j + 2, mid + 1, high, from, to, x);
        T[j] = min(T[2 * j + 1], T[2 * j + 2]);
    };
    function<int(int, int, int, int, int)> query = [&](int j, int low, int high, int from, int to) {
        if (low > high) { return 1; }
        if (to < low || high < from) { return 1; }
        if (from <= low && high <= to) { return T[j]; }
        push(j);
        int mid = (low + high) / 2;
        return min(query(2 * j + 1, low, mid, from, to), query(2 * j + 2, mid + 1, high, from, to));
    };
    dfs(0);
    update(0, 0, 2 * n - 1, tin[0], tout[0], 0);
    int Q; cin >> Q;
    while (Q--) {
        int t; cin >> t;
        int v; cin >> v; v--;
        if (t == 1) {
            int was_empty = query(0, 0, 2 * n - 1, tin[v], tout[v]) == 0;
            update(0, 0, 2 * n - 1, tin[v], tout[v], 1);
            if (was_empty && p[v] != -1) {
                update(0, 0, 2 * n - 1, tin[p[v]], tin[p[v]], 0);
                update(0, 0, 2 * n - 1, tout[p[v]], tout[p[v]], 0);
            }
        } else if (t == 2) {
            update(0, 0, 2 * n - 1, tin[v], tin[v], 0);
            update(0, 0, 2 * n - 1, tout[v], tout[v], 0);
        } else {
            cout << query(0, 0, 2 * n - 1, tin[v], tout[v]) << "\n";
        }
    }
}
