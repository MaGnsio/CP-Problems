/**
 *    author:  MaGnsi0
 *    created: 17.02.2024 14:55:23
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 5e3 + 5, OO = 1e10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> U(m), V(m);
    for (int i = 0; i < m; ++i) {
        cin >> U[i]; U[i]--;
        cin >> V[i]; V[i]--;
    }
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        if (a[U[i]] == a[V[i]]) { continue; }
        if (a[U[i]] < a[V[i]]) { swap(U[i], V[i]); }
        adj[U[i]].push_back(V[i]);
        deg[V[i]]++;
    }
    for (int i = 0; i < n; ++i) {
    }
    int64_t res = 0;
    vector<int64_t> ans(n);
    function<int64_t(int)> dfs = [&](int v) {
        if (ans[v]) { return ans[v]; }
        ans[v] = 1;
        vector<int64_t> dp(N, 0);
        for (int u : adj[v]) {
            dfs(u);
            for (int64_t sum = N - 1; sum >= a[u]; --sum) {
                dp[sum] = max(dp[sum - a[u]] + ans[u], dp[sum]);
            }
        }
        for (int64_t sum = a[v] - 1; sum >= 0; --sum) {
            ans[v] = max(ans[v], dp[sum] + 1);
        }
        res += ans[v] * b[v];
        return ans[v];
    };
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) { dfs(i); }
    }
    cout << res;
}
