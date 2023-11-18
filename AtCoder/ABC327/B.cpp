/**
 *    author:  MaGnsi0
 *    created: 06.11.2023 12:00:37
**/
#include <bits/stdc++.h>

using namespace std;

__int128 power(__int128 b, __int128 p) {
    __int128 res = 1;
    while (p) {
        if (p & 1) { res = res * b; }
        b = b * b;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    for (int64_t x = 1; x <= 16; ++x) {
        int64_t y = power(x, x);
        if (y == n) {
            cout << x;
            return 0;
        }
    }
    cout << -1;
}
