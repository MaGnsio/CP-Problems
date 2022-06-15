/**
 *    author:  MaGnsi0
 *    created: 10.03.2022 16:30:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        long long ans = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
        ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
        long long besta0, besta1, bestb0, bestb1;
        besta0 = besta1 = bestb0 = bestb1 = 1e16;
        for (int i = 1; i < n - 1; ++i) {
            besta0 = min(besta0, abs(a[0] - b[i]));
            bestb0 = min(bestb0, abs(b[0] - a[i]));
            besta1 = min(besta1, abs(a[n - 1] - b[i]));
            bestb1 = min(bestb1, abs(b[n - 1] - a[i]));
        }
        ans = min(ans, besta0 + besta1 + bestb0 + bestb1);
        ans = min(ans, abs(a[0] - b[0]) + besta1 + bestb1);
        ans = min(ans, abs(a[0] - b[n - 1]) + besta1 + bestb0);
        ans = min(ans, besta0 + abs(a[n - 1] - b[0]) + bestb1);
        ans = min(ans, besta0 + abs(a[n - 1] - b[n - 1]) + bestb0);
        ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[0]) + bestb1);
        ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[n - 1]) + bestb0);
        ans = min(ans, besta1 + abs(b[0] - a[0]) + abs(b[n - 1] - a[0]));
        ans = min(ans, besta0 + abs(b[0] - a[n - 1]) + abs(b[n - 1] - a[n - 1]));
        cout << ans << "\n";
    }
}
