/**
 *    author:  MaGnsi0
 *    created: 23.06.2023 17:16:12
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

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
    int64_t n, m;
    cin >> n >> m;
    int64_t sum = 0;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int64_t N = m + n, K = n + sum; 
    if (K > N) {
        cout << 0;
        return 0;
    }
    int64_t ans = 1;
    for (int64_t x = N; x > N - K; --x) {
        ans *= x;
        ans %= MOD;
    }
    for (int64_t x = 1; x <= K; ++x) {
        ans *= power(x, MOD - 2);
        ans %= MOD;
    }
    cout << ans;
}
