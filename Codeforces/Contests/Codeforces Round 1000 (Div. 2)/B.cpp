/**
 *    author:  MaGnsi0
 *    created: 22.01.2025 17:31:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int l; cin >> l; l--;
        int r; cin >> r; r--;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.begin() + l);
        sort(a.begin() + l, a.begin() + r + 1);
        sort(a.begin() + r + 1, a.end());
        for (int i = 1; i < l; ++i) {
            a[i] += a[i - 1];
        }
        for (int i = l + 1; i <= r; ++i) {
            a[i] += a[i - 1];
        }
        for (int i = r + 2; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int64_t ans = a[r];
        for (int i = l; i <= r; ++i) {
            int k = r - i + 1;
            if (k <= l) {
                ans = min(ans, a[r] - (a[r] - (i == l ? 0 : a[i - 1])) + a[k - 1]);
            }
            if (k < n - r) {
                ans = min(ans, a[r] - (a[r] - (i == l ? 0 : a[i - 1])) + a[r + k]);
            }
        }
        cout << ans << "\n";
    }
}
