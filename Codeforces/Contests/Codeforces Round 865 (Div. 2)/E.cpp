/**
 *    author:  MaGnsi0
 *    created: 09.04.2023 17:48:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n), adj_t(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[v - 1].push_back(u - 1);
        }
        queue<int> q;
        vector<int> d(n, -1);
        d[0] = 1;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& u : adj[v]) {
                if (d[u] == -1) {
                    d[u] = d[v] + 1;
                    for (auto& p : adj_t[u]) {
                        d[u] = min(d[u], d[p] + 1);
                    }
                    q.push(u);
                }
            }
        }
        if (count(d.begin(), d.end(), -1)) {
            cout << "INFINITE\n";
            continue;
        }
        cout << "FINITE\n";
        vector<int> I(n);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return d[i] < d[j];
            });
        vector<vector<int>> c(d[I[n - 1]]);
        for (int i = 0; i < n; ++i) {
            int j = I[i];
            c[d[j] - 1].push_back(j + 1);
        }
        vector<int> ans;
        for (int i = d[I[n - 1]] - 1; i >= 0; --i) {
            int cnt = i + 1;
            for (int j = d[I[n - 1]] - 1; j >= 0 && cnt; --j, --cnt) {
                for (auto& v : c[j]) {
                    ans.push_back(v);
                }
            }
        }
        cout << (int)ans.size() << "\n";
        for (auto& x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
