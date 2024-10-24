/**
 *    author:  MaGnsi0
 *    created: 24.10.2024 18:20:56
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n; n %= MOD;
        int64_t k; cin >> k;
        if (k == 1) {
            cout << (n % MOD) << "\n";
            continue;
        }
        vector<int64_t> f(2, 1);
        for (int j = 3; ; ++j) {
            int64_t f2 = (f[0] + f[1]) % k;
            f[0] = f[1]; f[1] = f2;
            if (f2 == 0) {
                cout << (n * j % MOD) << "\n";
                break;
            }
        }
    }
}
