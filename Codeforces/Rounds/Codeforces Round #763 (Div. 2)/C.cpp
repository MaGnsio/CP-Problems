/**
 *    author:  MaGnsi0
 *    created: 02.01.2022 19:29:53
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        auto ok = [&](int m) {
            vector<int> b = a;
            vector<int> have(n, 0);
            for (int i = n - 1; i >= 0; --i) {
                if (b[i] + have[i] < m) {
                    return false;
                }
                if (i < 2) {
                    continue;
                }
                int x = (b[i] + have[i] - m) / 3;
                if (3 * x > b[i]) {
                    x = b[i] / 3;
                }
                b[i] -= (3 * x);
                have[i - 1] += x;
                have[i - 2] += 2 * x;
            }
            return true;
        };
        int l = 0, r = 1e9, res;
        while (l <= r) {
            int m = (l + r) / 2;
            if (ok(m)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << res << "\n";
    }
}
