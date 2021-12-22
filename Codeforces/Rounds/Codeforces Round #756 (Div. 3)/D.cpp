/**
 *    author:  MaGnsi0
 *    created: 25.11.2021 16:25:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, root = -1;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0, x; i < n; ++i) {
            cin >> x, x--;
            if (x == i) {
                root = x;
                continue;
            }
            adj[x].push_back(i);
        }
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i], a[i]--;
            b[a[i]] = i;
        }
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int v) {
            visited[v] = true;
            for (auto& u : adj[v]) {
                if (!visited[u] && b[v] < b[u]) {
                    dfs(u);
                }
            }
        };
        dfs(root);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            ok &= visited[i];
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        long long v = 0, maxi = 0;
        vector<long long> res(n), d(n, 0);
        for (int i = 0; i < n; ++i) {
            res[a[i]] = (i ? max(maxi + 1 - d[a[i]], 1LL) : 0);
            d[a[i]] += res[a[i]];
            for (auto& u : adj[a[i]]) {
                d[u] = d[a[i]];
            }
            maxi = d[a[i]];
        }
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
