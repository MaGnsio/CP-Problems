/**
 *    author:  MaGnsi0
 *    created: 09.02.2022 20:59:41
**/
#include <bits/stdc++.h>

using namespace std;

long long F(long long n) {
    if (n < 0) {
        return 0;
    }
    long long dp[20][11][2], digit[20];
    memset(dp, -1, sizeof dp);
    for (long long i = 0, x = n; i < 20; ++i, x /= 10) {
        digit[i] = (x % 10);
    }
    function<long long(int, int, int)> solve = [&](int pos, int last, int tight) {
        if (pos == -1) {
            return 1LL;
        }
        long long& res = dp[pos][last][tight];
        if (res != -1) {
            return res;
        }
        res = 0;
        if (tight) {
            for (int i = 0; i < digit[pos]; ++i) {
                if (i != last) {
                    res += solve(pos - 1, (last == 10 && i == 0 ? 10 : i), !tight);
                }
            }
            if (digit[pos] != last) {
                res += solve(pos - 1, digit[pos], tight); 
            }
        } else {
            for (int i = 0; i < 10; ++i) {
                if (i != last) {
                    res += solve(pos - 1, (last == 10 && i == 0 ? 10 : i), tight);
                }
            }
        }
        return res;
    };
    for (int i = 19; i >= 0; --i) {
        if (digit[i]) {
            return solve(i, 10, 1);
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long l, r;
    cin >> l >> r;
    cout << F(r) - F(l - 1);
}
