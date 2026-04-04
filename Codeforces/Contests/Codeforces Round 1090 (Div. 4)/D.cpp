/**
 *    author:  MaGnsi0
 *    created: 04.04.2026 16:45:24
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

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
    vector<int64_t> primes;
    for (int i = 0; i < N; ++i) {
        if (is_prime[i]) { primes.push_back(i); }
    }
    assert((int)primes.size() >= int(1e4 + 2));
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> ans(1, 2);
        for (int i = 1; (int)ans.size() < n; ++i) {
            ans.push_back(primes[i] * primes[i - 1]);
        }
        for (int64_t x : ans) { cout << x << " "; }
        cout << "\n";
    }
}
