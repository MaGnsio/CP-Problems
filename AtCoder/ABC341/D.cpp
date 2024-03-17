/**
 *    author:  MaGnsi0
 *    created: 17.02.2024 14:15:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t m; cin >> m;
    int64_t k; cin >> k;
    int64_t lcm = n * m / __gcd(n, m);
    int64_t low = 1, high = 1e18, ans;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        int64_t x = (mid / n) + (mid / m) - 2 * (mid / lcm);
        if (x >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
