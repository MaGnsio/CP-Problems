/**
 *    author:  MaGnsi0
 *    created: 20.10.2023 17:20:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int64_t x; cin >> x;
        int64_t L; cin >> L;
        int64_t R; cin >> R;
        cout << "Case " << t << ": ";
        if (x % 2 == 0) {
            int64_t up = max(x - L, int64_t(0));
            int64_t down = R - L + 1;
            int64_t g = __gcd(up, down);
            up /= g, down /= g;
            cout << up << "/" << down << "\n";
            continue;
        }
        x /= 2;
        int64_t up = max(2 * x - L + 1, int64_t(0)), down = R - L + 1;
        for (__int128 p = 1; p + x <= R; p *= __int128(2)) {
            __int128 y = p + x;
            up += (L <= y) && (y < __int128(2) * p);
        }
        int64_t g = __gcd(up, down);
        up /= g, down /= g;
        cout << up << "/" << down << "\n";
    }
}
