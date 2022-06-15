/**
 *    author:  MaGnsi0
 *    created: 05.03.2022 13:54:56
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<long long> P(N, 1);
    for (int i = 1; i < N; ++i) {
        P[i] = 26 * P[i - 1];
        P[i] %= MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        long long ans = 0;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            ans += (s[i] - 'A') * P[(n + 1) / 2 - i - 1];
            ans %= MOD;
        }
        string t = s;
        for (int i = n - 1; i >= (n + 1) / 2; --i) {
            t[i] = t[n - i - 1];
        }
        ans += (t <= s);
        ans %= MOD;
        cout << ans << "\n";
    }
}
