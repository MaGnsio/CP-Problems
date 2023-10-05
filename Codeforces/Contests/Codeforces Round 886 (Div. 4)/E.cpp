/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 17:49:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, c;
        cin >> n >> c;
        vector<int64_t> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        function<bool(int64_t)> F = [&](int64_t x) {
            int64_t a = c;
            for (int i = 0; i < n; ++i) {
                if (__int128(s[i] + 2 * x) * __int128(s[i] + 2 * x) > __int128(c)) {
                    return false;
                }
                a -= (s[i] + 2 * x) * (s[i] + 2 * x);
                if (a < 0) { return false; }
            }
            return true;
        };
        int64_t low = 0, high = c, ans = 0;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            if (F(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
