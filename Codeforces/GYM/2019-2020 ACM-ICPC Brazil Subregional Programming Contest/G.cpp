/**
 *    author:  MaGnsi0
 *    created: 31.10.2023 21:09:16
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> hungarian(vector<vector<long double>>& adj) {
    int n = (int)adj.size() + 1, m = (int)adj[0].size() + 1;
    vector<int> ans(n - 1), p(m);
    vector<long double> u(n), v(m);
    for (int i = 1; i < n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> pre(m, -1);
        vector<long double> dist(m, 1e18);
        vector<bool> done(m + 1, false);
        do {
            done[j0] = true;
            int i0 = p[j0], j1;
            long double delta = 1e18;
            for (int j = 1; j < m; ++j) {
                if (!done[j]) {
                    long double cur = adj[i0 - 1][j - 1] - u[i0] - v[j];
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
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<long double>> a(n, vector<long double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            a[i][j] = -log(x);
        }
    }
    vector<int> ans(n);
    vector<int> b = hungarian(a);
    for (int i = 0; i < n; ++i) {
        ans[b[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
}
