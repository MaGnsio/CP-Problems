/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 16:21:52
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t sum(int64_t L, int64_t R) {
    int64_t low = L * (L - 1) / 2;
    int64_t high = R * (R + 1) / 2;
    return (high - low) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t m; cin >> m;
    int64_t r; cin >> r; r = __gcd(n, r);
    int64_t c; cin >> c; c = __gcd(m, c);
    int64_t r_cyc_len = n / __gcd(n, r);
    int64_t c_cyc_len = m / __gcd(m, c);
    int64_t a_cyc_len = lcm(r_cyc_len, c_cyc_len);
    int64_t r_cyc_tim = a_cyc_len / r_cyc_len;
    int64_t c_cyc_tim = a_cyc_len / c_cyc_len;
    int64_t r_start = (n + r - 1) % n + 1;
    int64_t c_start = (m + c - 1) % m + 1;
    int64_t r_cyc_sum = m * (r_cyc_len % MOD * (r_start - 1) % MOD + r % MOD * sum(1, r_cyc_len - 1) % MOD) % MOD;
    int64_t c_cyc_sum = (c_cyc_len % MOD * c_start % MOD + c % MOD * sum(1, c_cyc_len - 1) % MOD) % MOD;
    int64_t ans = (r_cyc_tim % MOD * r_cyc_sum % MOD + c_cyc_tim % MOD * c_cyc_sum % MOD) % MOD;
    cout << ans;
}
