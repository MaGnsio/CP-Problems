/**
 *    author:  MaGnsi0
 *    created: 27.03.2023 22:55:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int64_t> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int64_t z = (k + n - 1) / n;
    int64_t ans = 0;
    for (int i = 0; i < z; ++i) {
        int64_t y = a[i];
        int64_t x = min(n, k - i * n);
        ans += (y + x) * (y + x - 1) / 2;
        ans -= y * (y - 1) / 2;
    }
    for (int i = 0; i < k; ++i) {
        ans -= a[i];
    }
    cout << ans;
}

/*
 * if x guest in the column:
 *   let y be the highest one
 *   -> ans += (y + x) * (y + x - 1) / 2 - y * (y - 1) / 2 - sumOf(guests)
 *   -> maximize(y) & minimize(sumOf(guests))
 */
