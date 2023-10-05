/**
 *    author:  MaGnsi0
 *    created: 10.09.2023 17:11:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<int64_t> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        a--, b--;
        if (a < k && b < k) {
            cout << 0 << "\n";
        } else if (a < k) {
            int64_t ans = 4e9;
            for (int i = 0; i < k; ++i) {
                ans = min(ans, abs(x[i] - x[b]) + abs(y[i] - y[b]));
            }
            cout << ans << "\n";
        } else if (b < k) {
            int64_t ans = 4e9;
            for (int i = 0; i < k; ++i) {
                ans = min(ans, abs(x[i] - x[a]) + abs(y[i] - y[a]));
            }
            cout << ans << "\n";
        } else {
            int64_t ans1 = 4e9, ans2 = 4e9;
            for (int i = 0; i < k; ++i) {
                ans1 = min(ans1, abs(x[i] - x[a]) + abs(y[i] - y[a]));
                ans2 = min(ans2, abs(x[i] - x[b]) + abs(y[i] - y[b]));
            }
            cout << min(ans1 + ans2, abs(x[a] - x[b]) + abs(y[a] - y[b])) << "\n";
        }
    }
}
