/**
 *    author:  MaGnsi0
 *    created: 11.10.2022 17:38:46
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
        if (n == 1) {
            cout << "NO\n";
            continue;
        }
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; ++i) {
            int l = i - a[i];
            int r = i + a[i] + 1;
            if (l >= 0) {
                adj[l].push_back(i + 1);
            }
            if (r <= n) {
                adj[i].push_back(r);
            }
        }
        vector<bool> visted(n + 1, false);
        function<void(int)> dfs = [&](int v) {
            visted[v] = true;
            for (auto& u : adj[v]) {
                if (!visted[u]) {
                    dfs(u);
                }
            }
        };
        dfs(0);
        cout << (visted[n] ? "YES" : "NO") << "\n";
    }
}
