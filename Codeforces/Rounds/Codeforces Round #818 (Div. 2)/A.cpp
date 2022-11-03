/**
 *    author:  MaGnsi0
 *    created: 02.09.2022 16:33:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        int64_t x = n / 3;
        while (3 * x <= n) {
            x++;
        }
        int64_t ans = 5 * n - 2 * (n - (n + 2) / 2 + 1) - 2 * (n - x + 1);
        cout << ans << "\n";
    }
}
