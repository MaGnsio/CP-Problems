/**
 *    author:  MaGnsi0
 *    created: 02.06.2022 16:12:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        int64_t max_sum = a[m];
        for (int i = m + 1; i < n; ++i) {
            max_sum = max(max_sum, a[i] - a[i - m - 1]);
        }
        if (max_sum >= x) {
            ans = m + 1;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans;
}
