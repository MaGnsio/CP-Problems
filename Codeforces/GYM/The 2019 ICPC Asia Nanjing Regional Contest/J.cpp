/**
 *    author:  MaGnsi0
 *    created: 29.07.2022 05:41:03
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
pair<T, vector<T>> hungarian(vector<vector<T>>& adj) {
    if (adj.empty()) {
        return {0, {}};
    }
    int n = (int)adj.size() + 1, m = (int)adj[0].size() + 1;
    vector<T> u(n), v(m), p(m), ans(n - 1);
    for (int i = 1; i < n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> dist(m, INT_MAX), pre(m, -1);
        vector<bool> done(m + 1, false);
        do {
            done[j0] = true;
            int i0 = p[j0], j1, delta = INT_MAX;
            for (int j = 1; j < m; ++j) {
                if (!done[j]) {
                    int cur = adj[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < dist[j]) {
                        dist[j] = cur, pre[j] = j0;
                    }
                    if (dist[j] < delta) {
                        delta = dist[j], j1 = j;
                    }
                }
            }
            for (int j = 0; j < m; ++j) {
                if (done[j]) {
                    u[p[j]] += delta, v[j] -= delta;
                } else {
                    dist[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0]);
        while (j0) {
            int j1 = pre[j0];
            p[j0] = p[j1], j0 = j1;
        }
    }
    for (int j = 1; j < m; ++j) {
        if (p[j]) {
            ans[p[j] - 1] = j - 1;
        }
    }
    return {-v[0], ans};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n), p(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<int64_t>> adj(n, vector<int64_t>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                adj[i][j] += (b[i] + c[j] > a[k]) * p[k];
            }
            adj[i][j] *= -1;
        }
    }
    cout << -1 * hungarian(adj).first;
}