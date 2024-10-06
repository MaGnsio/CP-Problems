/**
 *    author:  MaGnsi0
 *    created: 06.10.2024 19:41:06
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int64_t W; cin >> W; W %= MOD;
        int64_t G; cin >> G; G %= MOD;
        int64_t L; cin >> L; L %= MOD;
        cout << (W - G + MOD) % MOD * (2 * L + 1) % MOD << "\n";
    }
}
