/**
 *    author:  MaGnsi0
 *    created: 10.07.2022 16:32:29
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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            if (a[i].first > a[i].second) {
                swap(a[i].first, a[i].second);
            }
            a[i].first--, a[i].second--;
        }
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            s.insert(a[i]);
        }
        bool ok = true;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            adj[a[i].first].push_back(a[i].second);
            adj[a[i].second].push_back(a[i].first);
            if (a[i].first == a[i].second) {
                ok = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if ((int)adj[i].size() > 2) {
                ok = false;
                break;
            }
            if ((int)adj[i].size() < 2) {
                continue;
            }
            if (s.count(make_pair(min(adj[i][0], adj[i][1]), max(adj[i][0], adj[i][1])))) {
                ok = false;
                break;
            }
        }
        vector<int> color(n, 0);
        vector<bool> visited(n, false);
        function<bool(int, int)> dfs = [&](int v, int c) {
            visited[v] = true;
            color[v] = c;
            for (auto& u : adj[v]) {
                if (visited[u] && color[u] == color[v]) {
                    return false;
                }
                if (!visited[u] && !dfs(u, c ^ 1)) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ok &= dfs(i, 0);
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
