/**
 *    author:  MaGnsi0
 *    created: 08.10.2021 17:11:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        bitset<30> b(k);
        long long res = 0, cur = 1, MOD = 1e9 + 7;
        for (int i = 0; i < 30; ++i) {
            if (b[i]) {
                res = (res + cur) % MOD;
            }
            cur = (cur * n) % MOD;
        }
        cout << res << "\n";
    }
}
