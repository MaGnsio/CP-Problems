/**
 *    author:  MaGnsi0
 *    created: 09.09.2023 22:18:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    int64_t x = 0, y = n * m;
    if (n >= m) {
        x = m * (m + 1) / 2;
    } else {
        x = n * (n + 1) / 2 + (m - n) * n;
    }
    int64_t g = __gcd(x, y);
    x /= g, y /= g;
    cout << x << "/" << y;
}
