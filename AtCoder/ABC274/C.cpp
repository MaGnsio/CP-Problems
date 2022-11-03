/**
 *    author:  MaGnsi0
 *    created: 25.10.2022 07:57:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(2 * n + 2);
    for (int i = 0; i < n; ++i) {
        adj[a[i]].push_back(2 * (i + 1));
        adj[2 * (i + 1)].push_back(a[i]);
        adj[a[i]].push_back(2 * (i + 1) + 1);
        adj[2 * (i + 1) + 1].push_back(a[i]);
    }
    vector<int> ans(2 * n + 2, 0);
    function<void(int, int, int)> dfs = [&](int v, int d, int p) {
        ans[v] = d;
        for (auto& u : adj[v]) {
            if (u != p) {
                dfs(u, d + 1, v);
            }
        }
    };
    dfs(1, 0, -1);
    for (int i = 1; i <= 2 * n + 1; ++i) {
        cout << ans[i] << "\n";
    }
}
