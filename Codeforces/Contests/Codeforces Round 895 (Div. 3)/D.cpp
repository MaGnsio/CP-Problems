/**
 *    author:  MaGnsi0
 *    created: 06.10.2023 19:40:56
**/
#include <bits/stdc++.h>

using namespace std;

int64_t sum(int64_t low, int64_t high) {
    low = low * (low - 1) / 2;
    high = high * (high + 1) / 2;
    return high - low;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, x, y;
        cin >> n >> x >> y;
        int64_t z = x * y / __gcd(x, y);
        x = (n / x) - (n / z);
        y = (n / y) - (n / z); 
        int64_t ans = sum(n - x + 1, n) - sum(1, y);
        cout << ans << "\n";
    }
}
