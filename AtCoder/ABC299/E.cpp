/**
 *    author:  MaGnsi0
 *    created: 22.04.2023 14:24:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int k;
    cin >> k;
    if (k == 0) {
        cout << "Yes\n";
        cout << string(n, '1');
        return 0;
    }
    vector<int> a(k), b(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i] >> b[i];
        a[i]--;
    }
    vector<bool> banned(n, false);
    function<vector<int>(int)> bfs = [&](int source) {
        vector<int> d(n, -1);
        queue<int> q;
        d[source] = 0, q.push(source);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (d[u] == -1) {
                    d[u] = d[v] + 1;
                    q.push(u);
                }
            }
        }
        return d;
    };
    for (int i = 0; i < k; ++i) {
        vector<int> d = bfs(a[i]);
        for (int j = 0; j < n; ++j) {
            if (d[j] < b[i]) {
                banned[j] = true;
            }
        }
    }
    string ans(n, '0');
    for (int i = 0; i < k; ++i) {
        bool ok = false;
        vector<int> d = bfs(a[i]);
        for (int j = 0; j < n; ++j) {
            if (!banned[j] && d[j] == b[i]) {
                ans[j] = '1';
                ok = true;
            }
        }
        if (ok == false) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    cout << ans;
}
