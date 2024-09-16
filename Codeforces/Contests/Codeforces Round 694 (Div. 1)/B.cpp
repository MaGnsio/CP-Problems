/**
 *    author:  MaGnsi0
 *    created: 16.09.2024 21:33:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> a, b;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            int mask = 1, y = x;
            if (b.count(x)) { a[b[x]]++; continue; }
            for (int j = 2; 1LL * j * j <= y; ++j) {
                int v = 0;
                while (y % j == 0) { y /= j; v ^= 1; }
                if (v) { mask *= j; }
            }
            if (y > 1) { mask *= y; }
            a[mask]++; b[x] = mask;
        }
        int even_masks = 0, odd_ans = 0, even_ans = 0;
        for (auto [mask, c] : a) {
            if ((c & 1) && (mask != 1)) {
                odd_ans = max(odd_ans, c);
            } else {
                even_ans = max(even_ans, c);
                even_masks += c;
            }
        }
        int Q; cin >> Q;
        while (Q--) {
            int64_t x; cin >> x;
            if (x == 0) {
                cout << max(odd_ans, even_ans) << "\n";
            } else {
                cout << max(odd_ans, even_masks) << "\n";
            }
        }
    }
}
