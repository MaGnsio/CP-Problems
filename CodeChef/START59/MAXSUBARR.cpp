/**
 *    author:  MaGnsi0
 *    created: 05.10.2022 16:57:13
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<int64_t> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        vector<int64_t> c(n), d(n);
        c[0] = a[0], d[n - 1] = a[n - 1];
        for (int i = 1; i < n; ++i) {
            c[i] = c[i - 1] + a[i];
            d[n - i - 1] = d[n - i] + a[n - i - 1];
        }
        int64_t max_pre = 0, max_suf = 0, add = 0;
        for (int i = 0; i < n; ++i) {
            max_pre = max(max_pre, c[i]);
            max_suf = max(max_suf, d[i]);
        }
        for (int i = 0; i < m; ++i) {
            add = max(add, add + b[i]);
        }
        int64_t max_sub = INT64_MIN, cur_max = 0;
        for (int i = 0; i < n; ++i) {
            cur_max += a[i];
            max_sub = max(max_sub, cur_max);
            if (cur_max < 0) {
                cur_max = 0;
            }
        }
        bool all_negative = true;
        for (int i = 0; i < n; ++i) {
            all_negative &= (a[i] < 0);
        }
        for (int i = 0; i < m; ++i) {
            all_negative &= (b[i] < 0);
        }
        int64_t ans = (all_negative ? max_sub : max({max_sub, max_pre + add, max_suf + add}));
        cout << ans << "\n";
    }
}
