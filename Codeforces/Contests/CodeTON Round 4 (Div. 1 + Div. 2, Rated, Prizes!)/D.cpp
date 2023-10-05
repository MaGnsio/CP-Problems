/**
 *    author:  MaGnsi0
 *    created: 31.03.2023 17:10:49
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e18 + 10;

int64_t F(int64_t a, int64_t b, int64_t h) {
    int64_t low = 1, high = OO;
    while (low <= high) {
        __int128 mid = low + (high - low) / 2;
        __int128 L = (mid > 1 ? __int128(mid - 2) * (a - b) + a + 1 : 1);
        __int128 R = __int128(mid - 1) * (a - b) + a;
        L = min(L, R);
        if (L <= h && h <= R) {
            return mid;
        } else if (h < L) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int Q;
        cin >> Q;
        int64_t min_h = 1, max_h = OO;
        while (Q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int64_t a, b, n;
                cin >> a >> b >> n;
                int64_t low = (n > 1 ? (n - 2) * (a - b) + a + 1 : 1);
                int64_t high = (n - 1) * (a - b) + a;
                low = min(low, high);
                if (max_h < low || high < min_h) {
                    cout << 0 << " ";
                } else {
                    min_h = max(min_h, low);
                    max_h = min(max_h, high);
                    cout << 1 << " ";
                }
            } else {
                int64_t a, b;
                cin >> a >> b;
                int64_t x = F(a, b, min_h);
                int64_t y = F(a, b, max_h);
                cout << (x == y && x != -1 ? x : -1) << " ";
            }
        }
        cout << "\n";
    }
}
