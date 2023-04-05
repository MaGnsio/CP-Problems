/**
 *    author:  MaGnsi0
 *    created: 21.01.2023 16:43:58
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e5 + 5, MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N, 1);
    for (int i = 1; i < N; ++i) {
        F[i] = F[i - 1] * i;
        F[i] %= MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        int64_t ans1 = F[n];
        ans1 *= n;
        ans1 %= MOD;
        ans1 *= (n - 1);
        ans1 %= MOD;
        ans1 *= power(2, MOD - 2);
        ans1 %= MOD;
        int64_t ans2 = F[n];
        ans2 *= n;
        ans2 %= MOD;
        ans2 *= (n - 1);
        ans2 %= MOD;
        ans2 *= power(4, MOD - 2);
        ans2 %= MOD;
        int64_t ans = (ans1 + 2 * ans2) % MOD;
        cout << ans << "\n";
    }
}
