/**
 *    author:  MaGnsi0
 *    created: 04.01.2023 03:14:00
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 65;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int time = 0;
    vector<int> tin(n, -1), tout(n, -1), euler_tour;
    function<void(int)> dfs = [&](int v) {
        tin[v] = time++;
        euler_tour.push_back(v);
        for (auto& u : adj[v]) {
            if (tin[u] == -1) {
                dfs(u);
            }
        }
        euler_tour.push_back(v);
        tout[v] = time++;
    };
    dfs(0);
    vector<bitset<M>> b(8 * n, 0), d(8 * n, 0);
    function<void(int)> propagte = [&](int j) {
        if (d[j] != 0) {
            b[j] = d[j];
            d[j] = 0;
            if (2 * j + 1 < 8 * n) {
                d[2 * j + 1] = b[j];
            }
            if (2 * j + 2 < 8 * n) {
                d[2 * j + 2] = b[j];
            }
        }
    };
    function<void(int, int, int, int, int, bitset<M>)> _update = [&](int j, int l, int r, int f, int t, bitset<M> val) {
        if (l > r) { return; }
        if (t < l || r < f) { return; }
        propagte(j);
        if (f <= l && r <= t) {
            b[j] = val;
            d[j] = val;
            return;
        }
        int m = (l + r) / 2;
        _update(2 * j + 1, l, m, f, t, val);
        _update(2 * j + 2, m + 1, r, f, t, val);
        propagte(2 * j + 1), propagte(2 * j + 2);
        b[j] = b[2 * j + 1] | b[2 * j + 2];
    };
    function<void(int, int, bitset<M>)> update = [&](int l, int r, bitset<M> val) {
        _update(0, 0, 2 * n - 1, l, r, val);
    };
    function<bitset<M>(int, int, int, int, int)> _query = [&](int j, int l, int r, int f, int t) {
        if (l > r) { return bitset<M>(0); }
        if (t < l || r < f) { return bitset<M>(0); }
        propagte(j);
        if (f <= l && r <= t) { return b[j]; }
        int m = (l + r) / 2;
        return _query(2 * j + 1, l, m, f, t) | _query(2 * j + 2, m + 1, r, f, t);
    };
    function<int(int, int)> query = [&](int l, int r) {
        return _query(0, 0, 2 * n - 1, l, r).count();
    };
    assert((int)euler_tour.size() == 2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        bitset<M> x(0);
        x[c[euler_tour[i]]] = 1;
        update(i, i, x); 
    }
    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int v, nc;
            cin >> v >> nc;
            bitset<M> x(0);
            x[nc] = 1;
            update(tin[v - 1], tout[v - 1], x);
        } else {
            int v;
            cin >> v;
            cout << query(tin[v - 1], tout[v - 1]) << "\n";
        }
    }
}
