/**
 *    author:  MaGnsi0
 *    created: 29.06.2023 18:24:54
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e16;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        vector<int64_t> b(n + 2, OO);
        for (int i = n; i >= 0; --i) {
            b[i] = min(b[i + 1], a[i]);
        }
        int64_t ans = 0, diff = 0;
        for (int i = 0; i <= n; ++i) {
            if (a[i] - b[i + 1] > diff) {
                ans = a[i];
                diff = a[i] - b[i + 1];
            }
        }
        cout << ans << "\n";
    }
}
