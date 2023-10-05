/**
 *    author:  MaGnsi0
 *    created: 16.05.2022 20:53:05
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            c[i]--;
        }
        vector<bool> already_chosen(n, false);
        for (int i = 0; i < n; ++i) {
            if (c[i] != -1) {
                already_chosen[c[i]] = true;
            }
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (c[i] == -1) {
                adj[a[i]].push_back(b[i]);
                adj[b[i]].push_back(a[i]);
            }
        }
        int ans = 1;
        vector<bool> visited(n, false);
        function<int(int)> dfs = [&](int v) {
            int res = 1;
            visited[v] = true;
            for (auto& u : adj[v]) {
                if (!visited[u]) {
                    res += dfs(u);
                }
            }
            return (already_chosen[v] ? -n : res);
        };
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int x = dfs(i);
                if (x > 1) {
                    ans *= 2;
                    ans %= MOD;
                }
            }
        }
        cout << ans << "\n";
    }
}
