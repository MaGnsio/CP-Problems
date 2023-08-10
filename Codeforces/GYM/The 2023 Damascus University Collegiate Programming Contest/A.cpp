/**
 *    author:  MaGnsi0
 *    created: 16.07.2023 02:07:42
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        vector<vector<int>> c(2 * n);
        for (int i = 0; i < n; ++i) {
            c[a[i] - 1].push_back(i);
            c[b[i] - 1].push_back(i);
        }
        bool bad = false;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < 2 * n; ++i) {
            bad |= (int)c[i].size() > 2;
            if ((int)c[i].size() != 2) { continue; }
            if (c[i][0] == c[i][1]) { continue; }
            adj[c[i][0]].emplace_back(c[i][1], (a[c[i][0]] == a[c[i][1]]) || (b[c[i][0]] == b[c[i][1]]));
            adj[c[i][1]].emplace_back(c[i][0], (a[c[i][0]] == a[c[i][1]]) || (b[c[i][0]] == b[c[i][1]]));
        }
        if (bad) {
            cout << -1 << "\n";
            continue;
        }
        int x = 0, y = 0;
        vector<int> color(n, -1);
        function<void(int, int)> dfs = [&](int v, int c) {
            color[v] = c;
            x += c == 0;
            y += c == 1;
            for (auto [u, w] : adj[v]) {
                if (color[u] == -1) {
                    dfs(u, c ^ w);
                } else {
                    bad |= (color[v] ^ w) != color[u];
                }
            }
        };
        int ans = 0;
        for (int v = 0; v < n; ++v) {
            if (color[v] == -1) {
                x = y = 0;
                dfs(v, 0);
                ans += min(x, y);
            }
        }
        cout << (bad ? -1 : ans) << "\n";
    }
}
