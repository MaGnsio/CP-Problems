/**
 *    author:  MaGnsi0
 *    created: 19.06.2023 20:29:09
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
    vector<int> ans(n), b(N), c(n);
    function<void(int, int, int)> dfs = [&](int v, int p, int s) {
        if (p == -1) {
            c[v] = a[v];
        } else {
            c[v] = __gcd(c[p], a[v]);
            ans[v] = c[p];
        }
        for (int x = 1; x * x <= a[v]; ++x) {
            if (a[v] % x) { continue; }
            b[x]++, b[a[v] / x] += a[v] != x * x;
            if (s - b[x] <= 1) { ans[v] = max(ans[v], x); }
            if (s - b[a[v] / x] <= 1) { ans[v] = max(ans[v], a[v] / x); }
        }
        for (int u : adj[v]) {
            if (u == p) { continue; }
            dfs(u, v, s + 1);
        }
        for (int x = 1; x * x <= a[v]; ++x) {
            if (a[v] % x) { continue; }
            b[x]--, b[a[v] / x] -= a[v] != x * x;
        }
    };
    dfs(0, -1, 1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
