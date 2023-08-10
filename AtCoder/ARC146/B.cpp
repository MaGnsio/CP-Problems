/**
 *    author:  MaGnsi0
 *    created: 22.06.2023 21:08:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m, k;
    cin >> n >> m >> k;
    vector<int64_t> a(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    function<bool(int)> F = [&](int b) {
        vector<int64_t> d(c.begin(), c.end());
        for (int i = 0; i < n; ++i) {
            if ((a[i] >> b) & 1) { continue; }
            d[i] += (1LL << b);
            for (int j = 0; j < b; ++j) {
                if ((a[i] >> j) & 1) {
                    d[i] -= (1LL << j);
                }
            }
        }
        sort(d.begin(), d.end());
        int64_t s = accumulate(d.begin(), d.begin() + k, int64_t(0));
        return s <= m;
    };
    function<void(int)> apply = [&](int b) {
        for (int i = 0; i < n; ++i) {
            if ((a[i] >> b) & 1) { continue; }
            c[i] += (1LL << b);
            for (int j = 0; j < b; ++j) {
                if ((a[i] >> j) & 1) {
                    a[i] ^= (1LL << j);
                    c[i] -= (1LL << j);
                }
            }
            a[i] ^= (1LL << b);
        }
    };
    int64_t ans = 0;
    for (int b = 30; b >= 0; --b) {
        if (F(b)) {
            ans |= (1LL << b);
            apply(b);
        }
    }
    cout << ans;
}
