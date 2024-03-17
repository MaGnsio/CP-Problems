/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 22:30:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t k; cin >> k;
    vector<vector<int64_t>> a(2, vector<int64_t>(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[0][i] >> a[1][i];
    }
    for (int i = 0; i < 2; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    vector<vector<int64_t>> sum(2, vector<int64_t>(n));
    sum[0][0] = a[0][0], sum[1][0] = a[1][0];
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < n; ++j) {
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    }
    function<bool(int64_t)> F = [&](int64_t s) {
        vector<int64_t> op(2, INT64_MAX);
        for (int i = 0; i < 2; ++i) {
            for (int64_t j = 0, x = 0; j < n; ++j) {
                int64_t L = a[i][j];
                int64_t R = a[i][j] + s;
                int64_t need = j * L - (j ? sum[i][j - 1] : 0);
                while (x < n && a[i][x] <= R) { x++; }
                need += sum[i][n - 1] - sum[i][x - 1] - (n - x) * R;
                op[i] = min(op[i], need);
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int64_t j = n - 1, x = n - 1; j >= 0; --j) {
                int64_t R = a[i][j];
                int64_t L = a[i][j] - s;
                int64_t need = sum[i][n - 1] - sum[i][j] - (n - j - 1) * R;
                while (x >= 0 && a[i][x] >= L) { x--; }
                need += (x + 1) * L - (x >= 0 ? sum[i][x] : 0);
                op[i] = min(op[i], need);
            }
        }
        return op[0] + op[1] <= k;
    };
    int64_t low = 0, high = 1e10, ans = high;
    while (low <= high) {
        int64_t mid = (low + high) / 2;
        if (F(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
