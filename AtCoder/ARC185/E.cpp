/**
 *    author:  MaGnsi0
 *    created: 13.10.2024 21:19:21
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e5 + 5, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> phi(N);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i < N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    int n; cin >> n;
    vector<int64_t> a(n), f(N);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t res = 0, p2 = 1;
    for (int i = 0; i < n; ++i) {
        res *= 2; res %= MOD;
        vector<int64_t> divisors;
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                divisors.push_back(j);
                divisors.push_back(a[i] / j);
            }
        }
        sort(divisors.begin(), divisors.end());
        divisors.resize(unique(divisors.begin(), divisors.end()) - divisors.begin());
        for (int64_t d : divisors) {
            res += f[d] * phi[d] % MOD; res %= MOD;
            f[d] += p2; f[d] %= MOD;
        }
        p2 *= 2; p2 %= MOD;
        cout << res << "\n";
    }
}
