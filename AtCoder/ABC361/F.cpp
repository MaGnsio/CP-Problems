/**
 *    author:  MaGnsi0
 *    created: 12.08.2024 23:53:15
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 64, OO = 2e18;

bool is_prime(int x) {
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) { return false; }
    }
    return true;
}

int64_t power(__int128 b, __int128 p) {
    __int128 res = 1;
    while (p) {
        if (res > OO / b) { return OO; }
        if (p & 1) { res = res * b; }
        b = b * b;
        p /= 2;
    }
    return res;
}

int64_t F(int64_t p, int64_t N) {
    int64_t low = 1, high = N, result = 0;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        if (power(mid, p) <= N) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    vector<int> primes;
    for (int i = 2; i < N; ++i) {
        if (is_prime(i)) { primes.push_back(i); }
    }
    int m = (int)primes.size();
    int64_t ans = 0;
    for (int mask = 1; mask < (1 << m); ++mask) {
        int64_t p = 1;
        for (int i = 0; i < m; ++i) {
            if (mask >> i & 1) {
                p *= primes[i];
            }
        }
        ans += (__builtin_popcount(mask) & 1 ? +1 : -1) * F(p, n);
    }
    cout << ans;
}
