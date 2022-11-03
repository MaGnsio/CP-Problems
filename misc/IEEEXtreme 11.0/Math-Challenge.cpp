/**
 *    author:  MaGnsi0
 *    created: 11.10.2022 22:13:00
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6 + 6, MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p, int64_t mod) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % mod; }
        b = b * b % mod;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> spf(N);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i < N; ++i) {
        if (spf[i] == i) {
            for (int j = i; j < N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        //(a ^ b) % p = (a ^ (b % (p - 1))) % p
        vector<int> p(N, 0);
        for (int i = b - c + 1; i <= b; ++i) {
            int x = i;
            while (x > 1) {
                p[spf[x]]++;
                x /= spf[x];
            }
        }
        for (int i = 2; i <= c; ++i) {
            int x = i;
            while (x > 1) {
                p[spf[x]]--;
                x /= spf[x];
            }
        }
        int64_t ans = a;
        for (int i = 2; i < N; ++i) {
            ans = power(ans, power(i, p[i], MOD - 1), MOD);
        }
        cout << ans << "\n";
    }
}
