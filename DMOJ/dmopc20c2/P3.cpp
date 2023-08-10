/**
 *    author:  MaGnsi0
 *    created: 14.04.2023 23:19:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> in(n, 0), inT(n, 0);
    vector<vector<int>> adj(n), adjT(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        in[v - 1]++, inT[u - 1]++;
        adj[u - 1].push_back(v - 1);
        adjT[v - 1].push_back(u - 1);
    }
    vector<int64_t> reachable(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        reachable[v] = a[v];
        for (int u : adjT[v]) {
            if (u == p) continue;
            dfs(u, v);
            reachable[v] += reachable[u];
        }
    };
    for (int i = 0; i < n; ++i) {
        if (inT[i] == 0) { dfs(i, -1); }
    }
    int64_t add = 0;
    vector<int64_t> dp(n, -1), size(n, 0);
    function<int64_t(int)> solve = [&](int i) {
        if (size[i]) { return size[i]; }
        dp[i] = a[i] * (a[i] - 1), size[i] = a[i];
        for (int j : adj[i]) {
            dp[i] += a[i] * solve(j);
            size[i] += solve(j);
        }
        for (int j : adj[i]) {
            add = max(add, (size[i] - size[j]) * (reachable[j] - reachable[i]));
        }
        return size[i];
    };
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) { solve(i); }
    }
    int64_t ans = accumulate(dp.begin(), dp.end(), int64_t(0));
    cout << ans + add << "\n";
}
