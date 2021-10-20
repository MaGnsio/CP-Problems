/**
 *    author:  MaGnsi0
 *    created: 14.10.2021 14:31:22
**/
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

bool dfs(vector<vector<pair<int, int>>>& adj, vector<int>& e, int target, int v, int par = -1) {
    if (v == target) {
        return true;
    }
    for (auto& [u, i] : adj[v]) {
        if (u == par) {
            continue;
        }
        if (dfs(adj, e, target, u, v)) {
            e[i]++;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<int> e(n - 1, 0);
    for (int i = 1; i < m; ++i) {
        dfs(adj, e, a[i], a[i - 1]);
    }
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += e[i];
    }
    if (((k + sum) % 2) || (k + sum < 0)) {
        cout << 0;
        return 0;
    }
    sort(e.begin(), e.end());
    vector<long long> dp(100005, 0);
    dp[0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 100004; j >= e[i]; --j) {
            dp[j] += dp[j - e[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[(k + sum) / 2];
}
