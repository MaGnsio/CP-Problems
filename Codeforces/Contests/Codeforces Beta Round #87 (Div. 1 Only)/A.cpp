/**
 *    author:  MaGnsi0
 *    created: 13/06/2021 18:00:47
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, ans = 1;
    cin >> n;
    vector<int> v(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (v[i] == -1) { 
            continue;
        }
        adj[v[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i] != -1) {
            continue;
        }
        vector<int> d(n + 1, -1);
        queue<int> q;
        q.push(i);
        d[i] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& u : adj[v]) {
                q.push(u);
                d[u] = d[v] + 1;
                ans = max(ans, d[u]);
            }
        }
    }
    cout << ans;
}
