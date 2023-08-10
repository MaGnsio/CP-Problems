/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 19:09:31
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

const int64_t S = power(6, MOD - 2);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.insert(x);
        }
        n = (int)a.size();
        int64_t ans = 1;
        for (int i = 0; i < n; ++i) {
            ans *= 3;
            ans %= MOD;
        }
        ans -= 3;
        ans += MOD;
        ans %= MOD;
        ans *= S;
        ans %= MOD;
        cout << ans << "\n";
    }
}
