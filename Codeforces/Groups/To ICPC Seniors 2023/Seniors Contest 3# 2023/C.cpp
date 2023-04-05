/**
 *    author:  MaGnsi0
 *    created: 06.02.2023 09:47:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("lights.in", "r", stdin);
    int64_t n, l, d;
    cin >> n >> l >> d;
    vector<pair<int64_t, int64_t>> a(n);
    for (int i = 0; i < n; ++i) {
        int64_t x, y;
        cin >> x >> y;
        a[i] = {max(x - y, int64_t(0)), min(x + y, l)};
    }
    sort(a.begin(), a.end());
    vector<pair<int64_t, int64_t>> b;
    int64_t cur_l = a[0].first, cur_r = a[0].second;
    for (int i = 1; i < n; ++i) {
        if (cur_r < a[i].first || a[i].second < cur_l) {
            b.emplace_back(cur_l, cur_r);
            cur_l = a[i].first;
            cur_r = a[i].second;
        } else {
            cur_l = min(cur_l, a[i].first);
            cur_r = max(cur_r, a[i].second);
        }
    }
    b.emplace_back(cur_l, cur_r);
    sort(b.begin(), b.end());
    int m = (int)b.size();
    if (b.back().second != l) {
        b.emplace_back(l, l);
        m++;
    }
    if (b[0].first != 0) {
        b.emplace_back(0, 0);
        m++;
    }
    sort(b.begin(), b.end());
    int64_t ans = min(2 * d, l);
    for (int i = 0; i < m; ++i) {
        int low = i, high = m - 1, j = i;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (b[mid].first - b[i].second <= 2 * d) {
                j = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans = max({ans, b[j].second - b[i].first, min(b[i].second - b[i].first + 2 * d, l)});
    }
    cout << ans;
}
