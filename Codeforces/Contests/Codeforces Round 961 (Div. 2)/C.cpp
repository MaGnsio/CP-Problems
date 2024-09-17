/**
 *    author:  MaGnsi0
 *    created: 17.09.2024 02:15:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1] && a[i] == 1) {
                ans = -1;
            }
        }
        if (ans == -1) {
            cout << ans << "\n";
            continue;
        }
        vector<int64_t> c(n);
        for (int i = 1; i < n; ++i) {
            c[i] = c[i - 1];
            int64_t x = a[i - 1], y = a[i];
            while (x != 1 && x * x <= y) {
                x *= x; c[i]--;
            }
            while (y < x) {
                y *= y; c[i]++;
            }
            c[i] = max(c[i], 0LL);
        }
        for (int i = 0; i < n; ++i) {
            ans += c[i];
        }
        cout << ans << "\n";
    }
}
