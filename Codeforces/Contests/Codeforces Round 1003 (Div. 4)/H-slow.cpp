/**
 *    author:  MaGnsi0
 *    created: 09.02.2025 17:54:09
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e5 + 5, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> P2(N, 1);
    for (int i = 1; i < N; ++i) {
        P2[i] = P2[i - 1] * 2 % MOD;
    }
    function<int64_t(string)> solve_slow = [&](string s) {
        int n = (int)s.size();
        int64_t res = 0;
        for (int i = 0; i < n; ++i) {
            res += P2[n - i - 1]; res %= MOD;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i]) { continue; }
                res += P2[j] * P2[n - i - 1] % MOD; res %= MOD;
            }
        }
        return res;
    };
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int Q; cin >> Q;
        while (Q--) {
            int j; cin >> j; j--;
            s[j] = (s[j] == '1' ? '0' : '1');
            cout << solve_slow(s) << " ";
        }
        cout << "\n";
    }
}
