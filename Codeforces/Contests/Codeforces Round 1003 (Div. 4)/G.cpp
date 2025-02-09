/**
 *    author:  MaGnsi0
 *    created: 09.02.2025 17:15:15
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (!is_prime[i]) { continue; }
        for (int j = 2 * i; j < N; j += i) {
            is_prime[j] = false;
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t primes_count = 0;
        map<int, int64_t> mp;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; mp[x]++;
            primes_count += is_prime[x];
        }
        int64_t ans = 0;
        for (auto [x, y] : mp) {
            if (is_prime[x]) {
                ans += y * (primes_count - y);
            }
        }
        ans /= 2;
        for (auto [x, y] : mp) {
            int x_ = x;
            vector<int> prime_factors;
            for (int i = 2; i * i <= x_; ++i) {
                while (x_ % i == 0) {
                    prime_factors.push_back(i);
                    x_ /= i;
                }
            }
            if (x_ > 1) { prime_factors.push_back(x_); }
            if ((int)prime_factors.size() == 2) {
                ans += y * (y + 1) / 2;
                ans += y * mp[prime_factors[0]];
                ans += y * mp[prime_factors[1]] * (prime_factors[0] != prime_factors[1]);
            }
        }
        cout << ans << "\n";
    }
}
