/**
 *    author:  MaGnsi0
 *    created: 30.03.2023 22:48:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> b(n), c(n);
    for (int i = 1; i < n; ++i) {
        b[i] = max(a[i - 1] + b[i - 1], a[i]) - a[i];
    }
    for (int i = n - 2; i >= 0; --i) {
        c[i] = max(a[i + 1] + c[i + 1], a[i]) - a[i];
    }
    vector<int64_t> d(n), e(n);
    for (int i = 0; i < n; ++i) {
        d[i] = b[i] + (i ? d[i - 1] : 0);
    }
    for (int i = n - 1; i >= 0; --i) {
        e[i] = c[i] + (i + 1 < n ? e[i + 1] : 0);
    }
    int64_t ans = min(d[n - 1], e[0]);
    for (int i = 1; i + 1 < n; ++i) {
        ans = min(ans, d[i - 1] + e[i + 1] + max({a[i - 1] + b[i - 1], a[i + 1] + c[i + 1], a[i]}) - a[i]);
    }
    cout << ans;
}
