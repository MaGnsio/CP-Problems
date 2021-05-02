//https://vjudge.net/contest/419723#problem/G
#include <bits/stdc++.h>
using namespace std;

long long Power (long long X, int Y, long long mod) {
    long long res = 1;
    while (Y) {
        if (Y & 1) {
            res = ((res % mod) * (X % mod)) % mod;
        }
        X = ((X % mod) * (X % mod)) % mod;
        Y >>= 1;
    }
    return (res + mod) % mod;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long L, R, LCM = 1, mod = 1e9 + 7;
    cin >> L >> R;
    int N = R - L + 1;
    vector<long long> V(N), Prime;
    vector<bool> isPrime(N + 1, true);
    iota(V.begin(), V.end(), L);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            Prime.push_back(i);
            for (int j = 2 * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 0; i < Prime.size(); ++i) {
        int maxi = 0;
        long long X = ((L + Prime[i] - 1) / Prime[i]) * Prime[i];
        for (int j = X - L; j < N; j += Prime[i]) {
            int cnt = 0;
            while (V[j] % Prime[i] == 0) {
                V[j] /= Prime[i];
                cnt++;
            }
            maxi = max(cnt, maxi);
        }
        LCM = ((LCM % mod) * (Power(Prime[i], maxi, mod))) % mod;
    }
    for (int i = 0; i < N; ++i) {
        LCM = ((LCM % mod) * (V[i] % mod)) % mod;
    }
    cout << LCM;
}

