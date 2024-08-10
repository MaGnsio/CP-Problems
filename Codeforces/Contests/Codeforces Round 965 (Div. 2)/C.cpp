/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 17:52:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<int> I(n);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
            return a[i] < a[j];
        });
        vector<int64_t> sum(n); sum[0] = a[I[0]];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + a[I[i]];
        }
        vector<vector<int64_t>> c(2);
        for (int i = 0; i < n; ++i) {
            c[b[i]].push_back(a[i]);
        }
        for (int i = 0; i < 2; ++i) {
            sort(c[i].begin(), c[i].end());
        }
        int s = (int)c[1].size();
        vector<int64_t> d(s);
        if (s) { d[0] = c[1][0]; }
        for (int i = 1; i < s; ++i) {
            d[i] = d[i - 1] + c[1][i];
        }
        function<bool(int64_t, int, int)> F = [&](int median, int m, int j) {
            int64_t C = c[0].end() - lower_bound(c[0].begin(), c[0].end(), median) - (a[I[j]] >= median);
            int64_t good = c[1].end() - lower_bound(c[1].begin(), c[1].end(), median);
            if (s == 0 || m == 0) { return 2 * (C + good) > (n - 1); }
            int low = 0, high = s - good - 1, add = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                int64_t need = (s - good - mid) * median - (d[s - good - 1] - (mid ? d[mid - 1] : 0));
                if (need <= m) {
                    add = s - good - mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return 2 * (C + good + add) > (n - 1);
        };
        function<int64_t(int, int)> get_median = [&](int j, int m) {
            int64_t low = 0, high = 2e9, median = 0;
            while (low <= high) {
                int64_t mid = (low + high) / 2;
                if (F(mid, m, j)) {
                    median = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return median;
        };
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = I[i];
            if (b[j]) {
                ans = max(ans, a[j] + get_median(i, 0) + k);
            } else {
                ans = max(ans, a[j] + get_median(i, k));
            }
        }
        cout << ans << "\n";
    }
}
