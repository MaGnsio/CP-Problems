/**
 *    author:  MaGnsi0
 *    created: 16.03.2024 01:12:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        map<int, vector<int>> adj;
        for (int i = 0; i < m; ++i) {
            int u; cin >> u;
            int v; cin >> v;
            int c; cin >> c;
            adj[u].push_back(n + c);
            adj[n + c].push_back(u);
            adj[v].push_back(n + c);
            adj[n + c].push_back(v);
        }
        int s; cin >> s;
        int e; cin >> e;
        queue<int> Q;
        map<int, int> ans;
        ans[s] = 0, Q.push(s);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int u : adj[v]) {
                if (ans.count(u)) { continue; }
                ans[u] = ans[v] + 1, Q.push(u);
            }
        }
        cout << ans[e] / 2 << "\n";
    }
}
