/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 10:50:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
    sort(c.begin(), c.end());
    int64_t ans = c[n - 1] - c[0];
    cout << ans;
}
