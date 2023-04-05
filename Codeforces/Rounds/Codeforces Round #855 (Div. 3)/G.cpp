/**
 *    author:  MaGnsi0
 *    created: 02.03.2023 21:27:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    const int64_t N = 2e5 + 5, p = 53, MOD = 1e9 + 9;
    vector<int64_t> P(N, 1);
    for (int i = 1; i < N; ++i) {
        P[i] = p * P[i - 1];
        P[i] %= MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        function<tuple<bool, int, int64_t>(int, int)> dfs = [&](int v, int parent) {
            int cnt = 0;
            tuple<bool, int, int64_t> ans = make_tuple(true, 1, 1);
            map<tuple<bool, int, int64_t>, int> mp;
            for (auto& u : adj[v]) {
                if (u == parent) { continue; }
                mp[dfs(u, v)]++;
            }
            for (auto& [x, y] : mp) {
                cnt += (y & 1);
                if (y & 1) { get<0>(ans) &= get<0>(x); }
                get<1>(ans) += y * get<1>(x);
                for (int j = 0; j < y; ++j) {
                    get<2>(ans) = (P[get<1>(x) + 1] * get<2>(ans)) % MOD + get<2>(x);
                    get<2>(ans) %= MOD;
                }
            }
            get<0>(ans) &= cnt < 2;
            get<2>(ans) *= p;
            get<2>(ans) %= MOD;
            return ans;
        };
        bool ok = get<0>(dfs(0, -1));
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
