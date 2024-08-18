/**
 *    author:  MaGnsi0
 *    created: 18.08.2024 21:47:30
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353; 
const int64_t HALF = 499122177; 

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t A; cin >> A;
    int64_t B; cin >> B;
    if (B == 0) {
        cout << 0 << "\n";
        return 0;
    }
    map<int64_t, int64_t> mp;
    for (int64_t i = 2; i * i <= A; ++i) {
        while (A % i == 0) { A /= i; mp[i]++; }
    }
    if (A != 1) { mp[A]++; }
    bool even = B % 2 == 0;
    int64_t ans = B % MOD;
    for (auto [p, c] : mp) {
        even |= c % 2 == 1;
        ans *= (B % MOD * c % MOD + 1) % MOD;
        ans %= MOD;
    }
    if (!even) { ans = (ans + MOD - 1) % MOD; }
    ans = HALF * ans % MOD;
    cout << ans;
}
