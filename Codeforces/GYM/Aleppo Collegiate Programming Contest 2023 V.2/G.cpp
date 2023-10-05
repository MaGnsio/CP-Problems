/**
 *    author:  MaGnsi0
 *    created: 29.08.2023 14:15:27
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> P2(N, 1);
    for (int i = 1; i < N; ++i) {
        P2[i] = 2 * P2[i - 1] % MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; mp[x]++;
        }
        bool all_in = true;
        int64_t ans = 0, C = 1, sum = n;
        for (int64_t mex = 0; mex <= n; ++mex) {
            if (!all_in) { break; }
            sum -= mp[mex];
            ans += mex * C % MOD * P2[sum] % MOD;
            ans %= MOD;
            all_in = all_in && mp[mex];
            C *= (P2[mp[mex]] + MOD - 1) % MOD;
            C %= MOD;
        }
        cout << ans << "\n";
    }
}
