/**
 *    author:  MaGnsi0
 *    created: 18.10.2024 18:58:19
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e18;

int64_t LCM(int64_t a, int64_t b, int64_t c = 1) {
    int64_t x = a / __gcd(a, b);
    if (x > OO / b) { return OO + 1; }
    int64_t y = x * b;
    int64_t z = y / __gcd(y, c);
    if (z > OO / c) { return OO + 1; }
    return z * c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t a; cin >> a;
    int64_t b; cin >> b;
    int64_t c; cin >> c;
    int64_t n; cin >> n;
    int64_t low = 1, high = OO, ans = -1;
    function<int64_t(int64_t)> F = [&](int64_t m) {
        int64_t ab = (m / LCM(a, b)) - (m / LCM(a, b, c));
        int64_t bc = (m / LCM(b, c)) - (m / LCM(a, b, c));
        int64_t ac = (m / LCM(a, c)) - (m / LCM(a, b, c));
        return ab + bc + ac;
    };
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        if (F(mid) >= n) {
            ans = mid; high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}
