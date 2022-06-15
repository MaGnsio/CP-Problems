/**
 *    author:  MaGnsi0
 *    created: 30.04.2022 16:34:18
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 4, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> P;
    for (int i = 1; i < N; ++i) {
        string s = to_string(i);
        bool ok = true;
        for (int j = 0; j < (int)s.size() / 2; ++j) {
            ok &= bool(s[j] == s[s.size() - j - 1]);
        }
        if (ok) {
            P.push_back(i);
        }
    }
    vector<int> dp(N, 0);
    dp[0] = 1;
    for (int i = 0; i < (int)P.size(); ++i) {
        for (int j = P[i]; j < N; ++j) {
            dp[j] += dp[j - P[i]];
            dp[j] %= MOD;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}
