/**
 *    author:  MaGnsi0
 *    created: 17.07.2023 11:10:17
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ropes.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int64_t L1, L2;
        cin >> L1 >> L2;
        cout << power(2, __gcd(L1, L2) - 1) << "\n";
    }
}
