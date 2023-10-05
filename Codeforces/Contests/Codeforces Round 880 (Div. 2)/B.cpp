/**
 *    author:  MaGnsi0
 *    created: 18.06.2023 17:45:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k, g;
        cin >> n >> k >> g;
        int64_t s = g / 2 - (g % 2 == 0);
        if (n * s >= k * g) {
            cout << k * g << "\n";
            continue;
        }
        int64_t r = k * g - n * s;
        int64_t ans = s * (n - 1);
        int64_t x = s + r, y = (g + 1) / 2;
        if (x % g >= y) {
            ans += (x % g) - g;
        } else {
            ans += x % g;
        }
        cout << min(ans, k * g) << "\n";
    }
}
