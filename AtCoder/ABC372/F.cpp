/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 16:06:33
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<int> u(m), v(m);
    for (int i = 0; i < m; ++i) {
        cin >> u[i]; u[i]--;
        cin >> v[i]; v[i]--;
    }
    vector<int64_t> dp(n); dp[0] = 1;
    for (int j = 0; j < k; ++j) {
        map<int, int64_t> add;
        for (int e = 0; e < m; ++e) {
            int u_ = ((u[e] - j) % n + n) % n;
            int v_ = ((v[e] - j - 1) % n + n) % n;
            add[v_] += dp[u_]; add[v_] %= MOD;
        }
        for (auto [v_, x] : add) {
            dp[v_] += x; dp[v_] %= MOD;
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[i]; ans %= MOD;
    }
    cout << ans << "\n";
}
