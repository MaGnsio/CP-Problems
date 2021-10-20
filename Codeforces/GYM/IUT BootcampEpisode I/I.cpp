/**
 *    author:  MaGnsi0
 *    created: 12/07/2021 00:01:41
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int ans = INT_MAX;
        vector<int> x(4), y(4), p(4);
        for (int i = 0; i < 4; ++i) {
            cin >> x[i] >> y[i];
        }
        iota(p.begin(), p.end(), 0);
        do {
            int x1 = x[p[0]], y1 = y[p[0]];
            int x2 = x[p[1]], y2 = y[p[1]];
            int x3 = x[p[2]], y3 = y[p[2]];
            int x4 = x[p[3]], y4 = y[p[3]];
            int r1 = max(x1, x3) - min(x2, x4), l1 = min(x1, x3) - max(x2, x4);
            int r2 = max(y1, y2) - min(y3, y4), l2 = min(y1, y2) - max(y3, y4);
            if (r1 < 0 || r2 < 0) {
                continue;
            }
            int d = abs(x1 - x3) + abs(x2 - x4) + abs(y1 - y2) + abs(y3 - y4) + 2 * max(0LL, max(l1, l2) - min(r1, r2));
            ans = min(ans, d);
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << "\n";
    }
}
