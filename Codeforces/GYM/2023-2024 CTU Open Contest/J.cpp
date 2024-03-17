/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 19:52:34
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    if (n == 2) {
        cout << 1;
    } else if (n == 3) {
        cout << 3;
    } else {
        int64_t ans = n;
        for (int i = 0; i < n - 3; ++i) {
            ans = (2 * ans) % MOD;
        }
        cout << ans;
    }
}
