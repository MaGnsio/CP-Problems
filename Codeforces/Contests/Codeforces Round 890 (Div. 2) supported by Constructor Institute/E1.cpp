/**
 *    author:  MaGnsi0
 *    created: 05.08.2023 22:35:05
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int v = 1; v < n; ++v) {
        int u; cin >> u; u--;
        adj[u].push_back(v);
    }
    int64_t ans = 0;
    vector<int64_t> s(n, 1);
    function<void(int)> dfs = [&](int v) {
        bitset<N> dp(0); dp[0] = 1;
        for (int u : adj[v]) {
            dfs(u); s[v] += s[u];
            dp |= (dp << s[u]);
        }
        int64_t val = 0;
        for (int64_t i = 0; i < N; ++i) {
            if (!dp[i]) { continue; }
            val = max(val, i * (s[v] - i - 1));
        }
        ans += val;
    };
    dfs(0);
    cout << ans;
}
