/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 02:36:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t k; cin >> k;
    int64_t x = n / (2 * k);
    int64_t y = n % (2 * k);
    int64_t ans = 10 * x;
    if (2 * y <= n) {
        ans += 5 * ((2 * y + 2 * k - 1) / (2 * k));
    } else {
        ans += 10 * ((y + 2 * k - 1) / (2 * k));
    }
    cout << ans;
}
