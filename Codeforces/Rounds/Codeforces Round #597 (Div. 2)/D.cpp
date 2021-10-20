/**
 *    author:  MaGnsi0
 *    created: 01/07/2021 20:12:13
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> x(n), y(n), c(n), k(n), p(n, -1), a;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            adj[i][j] = adj[j][i] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
        }
    }
    int res = 0;
    vector<pair<int, int>> mst;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (visited[j]) {
                continue;
            }
            if (v == -1 || c[j] < c[v]) {
                v = j;
            }
        }
        visited[v] = true;
        if (p[v] == -1) {
            a.push_back(v + 1);
        } else {
            mst.push_back({min(v + 1, p[v] + 1), max(v + 1, p[v] + 1)});
        }
        res += c[v];
        for (int j = 0; j < n; ++j) {
            if (adj[v][j] < c[j]) {
                c[j] = adj[v][j];
                p[j] = v;
            }
        }
    }
    cout << res << "\n";
    cout << a.size() << "\n";
    for (auto& x : a) {
        cout << x << " ";
    }
    cout << "\n" << mst.size() << "\n";
    for (auto& [u, v] : mst) {
        cout << u << " " << v << "\n";
    }
}
