/**
 *    author:  MaGnsi0
 *    created: 07.02.2023 11:11:23
**/
#include <bits/stdc++.h>

using namespace std;

int64_t OO = 1e18;

bool F(int64_t n, int64_t k, int64_t m, int64_t c, int64_t d, vector<int64_t> a, int64_t x) {
    int64_t cnt = 0;
    vector<int64_t> b(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= x) {
            cnt++;
        } else {
            if (d == 0) {
                if (a[i] + c < x) { continue; }
                int64_t l = max(i - m + 1, int64_t(0));
                int64_t r = i;
                assert(l <= r);
                b[l]++, b[r + 1]--;
            } else {
                if (a[i] + c + (m - 1) * d < x) { continue; }
                int64_t y = max(int64_t(0), (x - a[i] - c + d - 1) / d);
                if (i < y) { continue; }
                int64_t l = max(i - m + 1, int64_t(0));
                int64_t r = i - y;
                assert(l <= r);
                b[l]++, b[r + 1]--;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] + cnt >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, k, m, c, d;
    cin >> n >> k >> m >> c >> d;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t low = 0, high = OO, ans = 0;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        if (F(n, k, m, c, d, a, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans;
}
