/**
 *    author:  MaGnsi0
 *    created: 28.10.2025 17:44:59
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t primes[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 74, 53};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t ans = primes[15];
        for (int i = 0; i < n; ++i) {
            int64_t x; cin >> x;
            for (auto prime : primes) {
                if (__gcd(x, prime) == 1) {
                    ans = min(ans, prime);
                }
            }
        }
        cout << ans << "\n";
    }
}
