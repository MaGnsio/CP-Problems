/**
 *    author:  MaGnsi0
 *    created: 28.02.2023 21:51:51
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t L, R;
        cin >> L >> R;
        int64_t length = 0;
        while (L * (1LL << length) <= R) { length++; }
        int64_t k = length - 1;
        int64_t count = (R / (1LL << k)) - L + 1;
        if (k) {
            count += max(0LL, k * ((R / (3 * (1LL << (k - 1)))) - L + 1));
            count %= MOD;
        }
        cout << length << " " << count << "\n";
    }
}
