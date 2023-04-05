/**
 *    author:  MaGnsi0
 *    created: 08.11.2022 19:49:06
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;
    vector<int64_t> primes;
    for (int i = 2; i < N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int64_t a, b;
    cin >> a >> b;
    vector<int64_t> F(b - a + 1, 1);
    vector<int64_t> V(b - a + 1);
    iota(V.begin(), V.end(), a);
    for (int i = 0; i < (int)primes.size(); ++i) {
        for (int64_t j = primes[i] * ((a + primes[i] - 1) / primes[i]); j <= b; j += primes[i]) {
            int64_t x = primes[i];
            while (V[j - a] % primes[i] == 0) {
                V[j - a] /= primes[i];
                x *= primes[i];
            }
            F[j - a] *= (x - 1) / (primes[i] - 1);
        }
    }
    for (int64_t i = a; i <= b; ++i) {
        if (V[i - a] > 1) {
            F[i - a] *= (V[i - a] + 1);
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < b - a + 1; ++i) {
        ans += F[i];
    }
    cout << ans;
}
