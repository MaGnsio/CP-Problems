/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 07:28:04
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6, MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1; b %= MOD;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int v = 1; v < n; ++v) {
            int u; cin >> u; u--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int64_t ans = 0;
        vector<int64_t> size(n, 1);
        function<void(int, int)> dfs = [&](int v, int p) {
            vector<int64_t> b;
            for (int u : adj[v]) {
                if (u == p) { continue; }
                dfs(u, v); size[v] += size[u];
                b.push_back(size[u]);
            }
            b.push_back(n - size[v]);
            int64_t ones = n - 1, twos = 0;
            for (int64_t x : b) {
                twos += x * (n - x - 1) % MOD;
                twos %= MOD;
            }
            twos *= power(2, MOD - 2);
            twos %= MOD;
            ans += ones * (ones - 1) % MOD * power(2, MOD - 2) % MOD;
            ans %= MOD;
            ans += ones * twos % MOD;
            ans %= MOD;
            ans += twos * (twos - 1) % MOD * power(2, MOD - 2) % MOD;
            ans %= MOD;
        };
        dfs(0, -1);
        cout << ans << "\n";
    }
}
