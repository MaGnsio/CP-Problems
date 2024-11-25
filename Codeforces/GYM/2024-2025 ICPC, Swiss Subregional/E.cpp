/**
 *    author:  MaGnsi0
 *    created: 25.11.2024 20:58:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t m; cin >> m;
    int64_t k; cin >> k;
    vector<int64_t> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    function<bool(int64_t)> F = [&](int64_t x) {
        vector<int64_t> L(n), R(n);
        for (int i = 0; i < n; ++i) {
            L[i] = a[i] - b[x];
            R[i] = a[i] + b[x];
        }
        if (L[0] > 0) { return false; }
        if (R[n - 1] < k) { return false; }
        for (int i = 1; i < n; ++i) {
            if (R[i - 1] + 1 < L[i]) { return false; }
        }
        return true;
    };
    int64_t low = 0, high = m - 1, ans = -1;
    while (low <= high) {
        int64_t mid = (low + high) / 2;
        if (F(mid)) {
            ans = b[mid]; high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
