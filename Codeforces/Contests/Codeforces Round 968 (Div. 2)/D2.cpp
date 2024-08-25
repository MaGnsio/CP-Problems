/**
 *    author:  MaGnsi0
 *    created: 25.08.2024 18:24:01
**/
#include <bits/stdc++.h>

using namespace std;

int64_t sum(int64_t l, int64_t r) {
    if (l > r) { return 0; }
    int64_t y = r * (r + 1) / 2;
    int64_t x = l * (l - 1) / 2;
    return y - x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t m; cin >> m;
        int64_t N = 0;
        vector<int> get(n), give(n);
        for (int i = 0; i < n; ++i) {
            int k; cin >> k; N += k;
            set<int> s;
            for (int j = 0; j < k; ++j) {
                int x; cin >> x; s.insert(x);
            }
            int64_t mex = 0;
            while ((int)s.count(mex)) { mex++; }
            get[i] = mex;
            mex++;
            while ((int)s.count(mex)) { mex++; }
            give[i] = mex;
        }
        vector<vector<int>> adj(N + 2);
        for (int i = 0; i < n; ++i) {
            adj[get[i]].push_back(give[i]);
        }
        vector<int> dp(N + 2, -1);
        function<int(int)> solve = [&](int v) {
            if (dp[v] != -1) { return dp[v]; }
            dp[v] = v;
            for (int u : adj[v]) {
                dp[v] = max(dp[v], solve(u));
            }
            return dp[v];
        };
        int without_x = 0;
        for (int i = 0; i < n; ++i) {
            if ((int)adj[get[i]].size() > 1) {
                without_x = max(without_x, solve(get[i]));
            }
            without_x = max(without_x, get[i]);
        }
        int64_t ans = sum(N + 1, m); 
        for (int x = 0; x <= min(N, m); ++x) {
            ans += max(without_x, solve(x));
        }
        cout << ans << "\n";
    }
}
