/**
 *    author:  MaGnsi0
 *    created: 22.06.2023 12:09:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            char x; cin >> x;
            if (x == '0') { continue; }
            adj[u].push_back(v);
        }
    }
    function<int(int)> bfs = [&](int source) {
        vector<int> d(n, 0);
        queue<int> q;
        d[source] = 1;
        q.push(source);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (d[u]) { continue; }
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
        for (int u = 0; u < n; ++u) {
            for (int v : adj[u]) {
                if (abs(d[u] - d[v]) != 1) {
                    return -1;
                }
            }
        }
        int res = *max_element(d.begin(), d.end());
        return res;
    };
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, bfs(i));
    }
    cout << ans;
}
