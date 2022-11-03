/**
 *    author:  MaGnsi0
 *    created: 25.07.2022 22:43:20
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 3e5 + 5, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
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
        vector<int> d;
        for (int i = 1; i * i <= a[0]; ++i) {
            if (a[0] % i == 0) {
                d.push_back(i);
                if (a[0] != i * i) {
                    d.push_back(a[0] / i);
                }
            }
        }
        sort(d.begin(), d.end(), greater<int>());
        vector<int> ans(N, 0);
        function<int64_t(int, int, int)> dfs = [&](int v, int p, int x) {
            if (a[v] % x) {
                return int64_t(1);
            }
            int64_t res = 1;
            for (auto& u : adj[v]) {
                if (u == p) {
                    continue;
                }
                res *= dfs(u, v, x);
                res %= MOD;
            }
            res += p != -1;
            res %= MOD;
            return res;
        };
        for (int i = 0; i < (int)d.size() - 1; ++i) {
            ans[d[i]] = dfs(0, -1, d[i]);
            for (int j = 2 * d[i]; j < N; j += d[i]) {
                ans[d[i]] -= ans[j];
                ans[d[i]] += MOD;
                ans[d[i]] %= MOD;
            }
        }
        int64_t res = 0;
        for (int i = 2; i < N; ++i) {
            res += ans[i];
            res %= MOD;
        }
        cout << res << "\n";
    }
}
