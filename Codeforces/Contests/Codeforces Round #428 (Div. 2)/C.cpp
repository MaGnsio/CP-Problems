/**
 *    author:  MaGnsi0
 *    created: 20.06.2022 16:59:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    long double ans = 0;
    function<void(int, int, int, long double)> DFS = [&](int v, int p, int x, long double y) {
        if (v != 0 && adj[v].size() == 1) {
            ans += 1.0 * x * y;
            return;
        }
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            DFS(u, v, x + 1, 1.0 * y / ((int)adj[v].size() - (v != 0)));
        }
    };
    DFS(0, -1, 0, 1.0);
    cout << fixed << setprecision(8) << ans;
}
