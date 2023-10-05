/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 16:55:08
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
        int64_t ans = 4 * n + n * (n - 1) / 2 + 1 + (n - 2) * (n - 1) / 2;
        cout << ans << "\n";
    }
}
