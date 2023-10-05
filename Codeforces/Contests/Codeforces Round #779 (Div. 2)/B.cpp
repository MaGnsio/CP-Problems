/**
 *    author:  MaGnsi0
 *    created: 27.03.2022 16:27:08
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n & 1) {
            cout << 0;
        } else {
            long long ans = 1;
            for (int i = 1; i <= n / 2; ++i) {
                ans *= 1LL * i * i;
                ans %= MOD;
            }
            cout << ans;
        }
        cout << "\n";
    }
}
