/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 21:49:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t low; cin >> low;
    int64_t high; cin >> high;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; ++i) {
        p[i] = a[i] + p[i - 1];
    }
    vector<int64_t> s(n);
    s[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        s[i] = a[i] + s[i + 1];
    }
    vector<int64_t> b(n);
    b[n - 1] = min(high, a[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
        b[i] = min(b[i + 1] + a[i], high * (n - i));
    }
    vector<int64_t> c(n);
    c[0] = min(low, a[0]);
    for (int i = 1; i < n; ++i) {
        c[i] = min(c[i - 1] + a[i], low * (i + 1));
    }
    int64_t ans = min(b[0], c[n - 1]);
    for (int i = 0; i + 1 < n; ++i) {
        ans = min(ans, c[i] + b[i + 1]);
    }
    cout << ans;
}
