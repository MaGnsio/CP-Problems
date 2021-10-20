/**
 *    author:  MaGnsi0
 *    created: 24/09/2021 17:58:49
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N = 1e7 + 7;
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        double x, y;
        cin >> x >> y;
        int a = round(1e5 * x);
        int b = round(1e5 * y);
        int g = __gcd(a, b);
        a /= g, b /= g;
        if (a == b) {
            cout << 2 << " " << 2 << "\n";
            continue;
        }
        if (is_prime[a] && is_prime[b]) {
            cout << a << " " << b << "\n";
        } else {
            cout << "impossible\n";
        }
    }
}
