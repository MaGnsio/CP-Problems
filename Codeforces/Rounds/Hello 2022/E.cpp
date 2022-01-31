/**
 *    author:  MaGnsi0
 *    created: 09.01.2022 20:40:00
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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<long long>());
        vector<vector<long long>> b(m);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            b[i].resize(k);
            for (int j = 0; j < k; ++j) {
                cin >> b[i][j];
            }
        }
        vector<pair<int, pair<long long, long long>>> c(m);
        for (int i = 0; i < m; ++i) {
            c[i] = {i, {accumulate(b[i].begin(), b[i].end(), 0LL), (int)b[i].size()}};
        }
        sort(c.begin(), c.end(), [](pair<int, pair<long long, long long>> x, pair<int, pair<long long, long long>> y) {
                long long xd = x.second.first, xn = x.second.second;
                long long yd = y.second.first, yn = y.second.second;
                return (xd * yn > yd * xn);
           });
        vector<int> can(m, 0);
        for (int i = 0; i < m; ++i) {
            can[i] = (c[i].second.first <= a[i] * c[i].second.second);
        }
        for (int i = 1; i < m; ++i) {
            can[i] += can[i - 1];
        }
        vector<int> can_shift_down(m, 0);
        for (int i = 1; i < min(m + 1, n); ++i) {
            can_shift_down[i - 1] = (c[i - 1].second.first <= a[i] * c[i - 1].second.second);
        }
        for (int i = 1; i < m; ++i) {
            can_shift_down[i] += can_shift_down[i - 1];
        }
        vector<int> can_shift_up(m, 0);
        for (int i = 1; i < m; ++i) {
            can_shift_up[i] = (c[i].second.first <= a[i - 1] * c[i].second.second);
        }
        for (int i = 1; i < m; ++i) {
            can_shift_up[i] += can_shift_up[i - 1];
        }
        vector<vector<int>> res(m);
        for (int i = 0; i < m; ++i) {
            res[i].resize(b[i].size());
        }
        for (int i = 0; i < m; ++i) {
            int idx = c[i].first;
            for (int j = 0; j < (int)b[idx].size(); ++j) {
                long long den = c[i].second.first - b[idx][j], num = c[i].second.second - 1;
                int l = 0, r = m - 1, y = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (den <= num * a[mid]) {
                        y = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (y == -1) {
                    res[idx][j] = 0;
                } else if (y >= i) {
                    int x = (i ? can[i - 1] : 0) + (can_shift_up[y] - can_shift_up[i]) + (can[m - 1] - can[y]);
                    res[idx][j] = (x == m - 1);
                } else {
                    int x = (y ? can[y - 1] : 0) + ((i ? can_shift_down[i - 1] : 0) - (y ? can_shift_down[y - 1] : 0)) + (can[m - 1] - can[i]);
                    res[idx][j] = (x == m - 1);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < (int)res[i].size(); ++j) {
                cout << res[i][j];
            }
        }
        cout << "\n";
    }
}
