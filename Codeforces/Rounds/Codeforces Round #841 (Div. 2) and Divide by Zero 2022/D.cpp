/**
 *    author:  MaGnsi0
 *    created: 27.12.2022 17:58:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        function<bool(int)> ok = [&](int x) {
            vector<vector<int>> b(n, vector<int>(m));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    b[i][j] = x <= a[i][j];
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j < m; ++j) {
                    b[i][j] += b[i][j - 1];
                }
            }
            for (int j = 0; j < m; ++j) {
                for (int i = 1; i < n; ++i) {
                    b[i][j] += b[i - 1][j];
                }
            }
            for (int i = 0; i + x - 1 < n; ++i) {
                for (int j = 0; j + x - 1 < m; ++j) {
                    int cnt = b[i + x - 1][j + x - 1];
                    if (i) {
                        cnt -= b[i - 1][j + x - 1];
                    }
                    if (j) {
                        cnt -= b[i + x - 1][j - 1];
                    }
                    if (i && j) {
                        cnt += b[i - 1][j - 1];
                    }
                    if (cnt == x * x) {
                        return true;
                    }
                }
            }
            return false;
        };
        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (ok(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
