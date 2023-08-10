/**
 *    author:  MaGnsi0
 *    created: 19.06.2023 14:27:56
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
    int n;
    cin >> n;
    map<int64_t, int64_t> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int64_t ans = 1, z = 1;
    for (auto [x, y] : mp) {
        int64_t val = power(x, y * (y + 1) / 2);
        ans = power(ans, y + 1) * power(val, z) % MOD;
        z = z * (y + 1) % (MOD - 1);
    }
    cout << ans;
}

/*
 * Euler's theorem is a generalization of Fermat's little theorem:
 * for any modulus n and any integer a coprime to n, one has:
 * a^Ø(n) ≡ 1 (mod n)
 * A corollary of Euler's theorem is:
 * for every positive integer n, if the integer a is coprime with n then:
 * x ≡ y (mod Ø(n)) implies a^x ≡ a^y (mod n)
 * ∴ if n is prime → Ø(n) = n - 1 → x ≡ [x % (n - 1)] (mod (n - 1))
 */
