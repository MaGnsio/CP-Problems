/**
 *    author:  MaGnsi0
 *    created: 17.09.2023 15:01:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int primes = 0;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) { primes++; }
            while (n % i == 0) { n /= i; }
        }
        primes += (n > 1);
        cout << (primes > 1 ? "Yes" : "No") << "\n";
    }
}
