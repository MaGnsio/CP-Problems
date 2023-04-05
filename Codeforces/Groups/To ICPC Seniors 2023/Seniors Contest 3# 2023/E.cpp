/**
 *    author:  MaGnsi0
 *    created: 06.02.2023 09:39:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("magic.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int cur_sum = 0;
            bool found_sum = true;
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 0) {
                    found_sum = false;
                    break;
                }
                cur_sum += a[i][j];
            }
            if (found_sum) {
                sum = cur_sum;
            }
        }
        for (int j = 0; j < n; ++j) {
            int cur_sum = 0;
            bool found_sum = true;
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == 0) {
                    found_sum = false;
                    break;
                }
                cur_sum += a[i][j];
            }
            if (found_sum) {
                sum = cur_sum;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                cnt += a[i][j] == 0;
            }
            if (cnt != 1) { continue; }
            int cur_sum = 0, x, y;
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 0) {
                    x = i, y = j;
                }
                cur_sum += a[i][j];
            }
            a[x][y] = sum - cur_sum;
            ans.push_back(a[x][y]);
        }
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += a[i][j] == 0;
            }
            if (cnt != 1) { continue; }
            int cur_sum = 0, x, y;
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == 0) {
                    x = i, y = j;
                }
                cur_sum += a[i][j];
            }
            a[x][y] = sum - cur_sum;
            ans.push_back(a[x][y]);
        }
        sort(ans.begin(), ans.end());
        cout << ans[0] << " " << ans[1] << "\n";
    }
}
