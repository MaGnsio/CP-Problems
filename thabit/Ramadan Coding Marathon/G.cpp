/**
 *    author:  MaGnsi0
 *    created: 12.04.2022 05:19:06
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int ans = a[k - 1];
        for (int i = 0; i <= n; ++i) {
            int X = i, Y = 0;
            for (int j = 0; j < 20; ++j) {
                if (((X >> j) & 1) ^ ((k >> j) & 1)) {
                    Y |= (1 << j);
                }
            }
            if (X + Y > n) {
                continue;
            }
            ans = max(ans, (X ? a[X - 1] : 0) + (Y ? a[n - 1] - (n - 1 - Y >= 0 ? a[n - 1 - Y] : 0) : 0));
        }
        cout << ans << "\n";
    }
}
