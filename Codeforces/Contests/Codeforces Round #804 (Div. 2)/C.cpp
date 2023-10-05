/**
 *    author:  MaGnsi0
 *    created: 04.07.2022 16:34:10
**/
#include <bits/stdc++.h>

using namespace std;

int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i]] = i;
        }
        if (n <= 2) {
            cout << 1 << "\n";
            continue;
        }
        int64_t ans = 1;
        for (int i = 2, l = min(b[0], b[1]), r = max(b[0], b[1]); i < n; ++i) {
            if (l < b[i] && b[i] < r) {
                ans *= int64_t(r - l + 1 - i);
                ans %= MOD;
            } else {
                l = min(l, b[i]);
                r = max(r, b[i]);
            }
        }
        cout << ans << "\n";
    }
}
