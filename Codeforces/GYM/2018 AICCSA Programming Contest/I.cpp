/**
 *    author:  MaGnsi0
 *    created: 09.10.2021 14:33:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, c, l = 1, r = 0, res = -1;
        cin >> n >> m >> c;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                a[i][j] = (a[i][j] + c - 1) / c;
                r += a[i][j];
            }
        }
        auto ok = [=](int x) {
            int free = x, to_be_free = 0;
            vector<int> s(n, 0);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (free + s[j] < a[j][i]) {
                        return false;
                    }
                    free += min(s[j] - a[j][i], 0);
                    to_be_free += max(s[j] - a[j][i], 0);
                    s[j] = a[j][i];
                }
                free += to_be_free;
                to_be_free = 0;
            }
            return true;
        };
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << res << "\n";
    }
}
