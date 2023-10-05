/**
 *    author:  MaGnsi0
 *    created: 15.09.2023 17:30:09
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t F(int64_t x) {
    int64_t res = 1;
    while (x) {
        res = res * (x % 10) % MOD;
        x /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t low, high; 
        cin >> low >> high;
        if (high - low + 1 > 10) {
            cout << 0 << "\n";
        } else {
            int64_t ans = 1;
            for (int64_t x = low; x <= high; ++x) {
                ans = ans * F(x) % MOD;
            }
            cout << ans << "\n";
        }
    }
}
