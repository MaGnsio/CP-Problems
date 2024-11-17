/**
 *    author:  MaGnsi0
 *    created: 17.11.2024 17:49:21
**/
#include <bits/stdc++.h>

using namespace std;

int64_t N = 1e6 + 6, MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<int>> primes(N);
    for (int i = 2; i < N; ++i) {
        if (!primes[i].empty()) { continue; }
        for (int j = i; j < N; j += i) {
            primes[j].push_back(i);
        }
    }
    int n; cin >> n;
    int64_t ans = 1;
    vector<int64_t> a(n), total(N);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    function<void(int, int64_t)> add = [&](int x, int64_t val) {
        vector<int> p = primes[x];
        int m = (int)p.size();
        for (int mask = 1; mask < (1 << m); ++mask) {
            int y = 1;
            for (int64_t j = 0; j < m; ++j) {
                if (mask >> j & 1) { y *= p[j]; }
            }
            total[y] += val; total[y] %= MOD;
        }
    };
    function<int64_t(int64_t)> get = [&](int x) {
        int64_t res = 0;
        vector<int> p = primes[x];
        int m = (int)p.size();
        for (int mask = 1; mask < (1 << m); ++mask) {
            int y = 1;
            for (int64_t j = 0; j < m; ++j) {
                if (mask >> j & 1) { y *= p[j]; }
            }
            res += (__builtin_popcount(mask) & 1 ? +1 : -1) * total[y]; res += MOD; res %= MOD;
        }
        return res;
    };
    add(a[n - 1], 1);
    for (int i = n - 2; i >= 0; --i) {
        ans = get(a[i]);
        add(a[i], ans);
    }
    cout << ans;
}
