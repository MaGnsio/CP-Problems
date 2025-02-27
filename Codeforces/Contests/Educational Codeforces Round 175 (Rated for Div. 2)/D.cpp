/**
 *    author:  MaGnsi0
 *    created: 27.02.2025 17:09:40
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> d(n);
        vector<vector<int>> adj(n);
        for (int v = 1; v < n; ++v) {
            int u; cin >> u; u--;
            adj[u].push_back(v);
            d[v] = d[u] + 1;
        }
        vector<int> I(n);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
            return d[i] > d[j];
        });
        vector<int64_t> ansv(n), ansd(n + 1);
        for (int i_ = 0; i_ < n; ++i_) {
            int i = I[i_];
            ansv[i] = (ansd[d[i] + 1] + 1) % MOD;
            if (i) {
                for (int j : adj[i]) {
                    ansv[i] -= ansv[j]; ansv[i] += MOD; ansv[i] %= MOD;
                }
            }
            ansd[d[i]] += ansv[i]; ansd[d[i]] %= MOD;
        }
        cout << ansv[0] << "\n";
    }
}
