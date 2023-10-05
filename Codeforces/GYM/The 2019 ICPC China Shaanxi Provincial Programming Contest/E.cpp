/**
 *    author:  MaGnsi0
 *    created: 15.09.2023 17:13:20
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
        string s;
        cin >> s;
        function<bool(int)> F = [&](int x) {
            int last = -2 * n, y = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') { continue; }
                if (s[i] == '1') {
                    if (i - last + 1 > x) {
                        last = i, y++;
                    }
                }
            }
            return y <= k;
        };
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
