/**
 *    author:  MaGnsi0
 *    created: 14.05.2022 16:06:26
**/
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));
        int curr = 0, curv = 1;
        while (curv <= n * n) {
            for (int j = curr; j < n - curr; ++j) {
                a[curr][j] = curv++;
            }
            for (int i = curr + 1; i < n - curr; ++i) {
                a[i][n - curr - 1] = curv++;
            }
            for (int j = n - curr - 2; j >= curr; --j) {
                a[n - curr - 1][j] = curv++;
            }
            for (int i = n - curr - 2; i > curr; --i) {
                a[i][curr] = curv++;
            }
            curr++;
        }
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<int> x, y, v;
        dp[n / 2][n / 2][0] = true;
        x.push(n / 2), y.push(n / 2), v.push(0);
        while (!x.empty()) {
            int r = x.front(), c = y.front(), d = v.front();
            x.pop(), y.pop(), v.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr < 0 || nr >= n) {
                    continue;
                }
                if (nc < 0 || nc >= n) {
                    continue;
                }
                if (a[nr][nc] > a[r][c]) {
                    continue;
                }
                if (d + 1 > k) {
                    continue;
                }
                if (dp[nr][nc][d + 1]) {
                    continue;
                }
                dp[nr][nc][d + 1] = true;
                x.push(nr), y.push(nc), v.push(d + 1);
            }
        }
        vector<pair<int, int>> ans;
        function<void(int, int, int)> build = [&](int r, int c, int d) {
            if (d == 0) {
                return;
            }
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr < 0 || nr >= n) {
                    continue;
                }
                if (nc < 0 || nc >= n) {
                    continue;
                }
                if (a[nr][nc] < a[r][c]) {
                    continue;
                }
                if (!dp[nr][nc][d - 1]) {
                    continue;
                }
                if (a[nr][nc] - a[r][c] != 1) {
                    ans.push_back(make_pair(a[r][c], a[nr][nc]));
                }
                build(nr, nc, d - 1);
                break;
            }
        };
        if (dp[0][0][k]) {
            build(0, 0, k);
            cout << "Case #" << t << ": " << (int)ans.size() << "\n";
            for (int i = 0; i < (int)ans.size(); ++i) {
                cout << ans[i].first << " " << ans[i].second << "\n";
            }
        } else {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << "\n";
        }
    }
}
