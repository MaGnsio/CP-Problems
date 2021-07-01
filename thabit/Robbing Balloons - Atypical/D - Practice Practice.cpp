/**
 *    author:  MaGnsi0
 *    created: 04/06/2021 20:53:14
**/
#include <bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7;

long long F(long long n, long long k, long long x, long long y) {
    long long res = (((n * (n + 1) / 2) % m) * x) % m;
    res += ((((n / k) * ((n % k) + 1)) % m) * y) % m;
    if (n < k) {
        return res;
    }
    long long a = n / k - 1;
    long long t = ((n / k) * y) % m;
    res += (((((a * (a + 1) / 2) % m) * y) % m) * k) % m;
    res -= t;
    res = (res + m) % m;
    return res;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    cout << (F(r, k, x, y) - F(l - 1, k, x, y) + m) % m;
}
