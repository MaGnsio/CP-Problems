/**
 *    author:  MaGnsi0
 *    created: 30.11.2022 16:32:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        if (k >= n / 2) {
            cout << n * (n - 1) / 2 << "\n";
            continue;
        }
        int64_t ans = n * (n - 1) / 2 - (n - k) * (n - k - 1) / 2;
        ans += k * (n - 2 * k);
        ans += k * (k - 1) / 2;
        cout << ans << "\n";
    }
}
