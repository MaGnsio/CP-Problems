/**
 *    author:  MaGnsi0
 *    created: 14.07.2023 16:01:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        if (n & 1) {
            cout << -1 << "\n";
            continue;
        }
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]]++;
        }
        bool odds = false;
        for (auto [_, x] : mp) {
            odds |= (x & 1);
        }
        if (odds) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> size(n, 1), parent(n, -1);
        function<void(int, int)> dfs = [&](int v, int p) {
            parent[v] = p;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v); size[v] += size[u];
            }
        };
        dfs(0, -1);
        bool ok = false;
        map<int, int> b;
        function<void(int, int)> collect = [&](int v, int p) {
            b[a[v]]++;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                collect(u, v);
            }
        };
        for (int i = 0; i < n; ++i) {
            if (size[i] == n / 2) {
                collect(i, parent[i]);
                ok = true;
                break;
            }
        }
        assert(count(size.begin(), size.end(), n / 2) <= 1);
        if (ok == false) {
            cout << -1 << "\n";
            continue;
        }
        int ans = 0;
        for (auto& [c, x] : b) {
            if (mp[c] / 2 < x) {
                ans += x - mp[c] / 2;
            }
        }
        cout << ans << "\n";
    }
}
