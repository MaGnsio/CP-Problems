/**
 *    author:  MaGnsi0
 *    created: 21.04.2023 23:48:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i & 1) { a[i] *= -1; }
    }
    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int64_t ans = a[r] - (l ? a[l - 1] : 0);
        if (l & 1) { ans *= -1; }
        cout << ans << "\n";
    }
}
