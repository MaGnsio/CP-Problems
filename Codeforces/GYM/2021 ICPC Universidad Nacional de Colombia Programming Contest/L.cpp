/**
 *    author:  MaGnsi0
 *    created: 19.03.2022 20:04:10
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
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
    bitset<N> dp(1);
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        dp |= (dp << x);
    }
    set<int> s;
    for (int i = 0; i < N; ++i) {
        if (dp[i]) {
            s.insert(i);
        }
    }
    long long ans = 0;
    function<int(int, int)> dfs = [&](int v, int p) {
        int maxi = a[v];
        for (auto& u : adj[v]) {
            if (u == p) {
                continue;
            }
            maxi = max(maxi, dfs(u, v));
        }
        auto it = s.lower_bound(maxi - a[v]);
        if (it == s.end()) {
            cout << -1;
            exit(0);
        } else {
            ans += a[v] + *it;
            return (a[v] + *it);
        }
    };
    dfs(0, -1);
    cout << ans;
}
