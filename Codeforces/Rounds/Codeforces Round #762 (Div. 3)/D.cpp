/**
 *    author:  MaGnsi0
 *    created: 05.01.2022 21:24:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        auto ok = [&](int x) {
            bool have_two = false;
            vector<bool> can(n, false);
            for (int i = 0; i < m; ++i) {
                int cnt = 0;
                for (int j = 0; j < n; ++j) {
                    if (a[i][j] >= x) {
                        can[j] = true;
                        cnt++;
                    }
                }
                have_two |= (cnt > 1);
            }
            if (!have_two && n > 1) {
                return false;
            }
            for (int i = 0; i < n; ++i) {
                have_two &= can[i];
            }
            return have_two;
        };
        int l = 1, r = 1e9, res;
        while (l <= r) {
            int m = l + (r - l) / 2;
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
