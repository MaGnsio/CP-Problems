/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 15:09:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m, k;
    cin >> n >> m >> k;
    if ((2 * n * m) % k) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int64_t K = k;
    if (K % 2 == 0) { K /= 2; }
    int64_t g = __gcd(n, K);
    int64_t X1 = 0, Y1 = 0;
    int64_t X2 = n / g, Y2 = 0;
    int64_t X3 = 0, Y3 = m / (K / g);
    if (k & 1) {
        if (2 * X2 <= n) {
            X2 *= 2;
        } else {
            Y3 *= 2;
        }
    }
    cout << X1 << " " << Y1 << "\n";
    cout << X2 << " " << Y2 << "\n";
    cout << X3 << " " << Y3 << "\n";
}
