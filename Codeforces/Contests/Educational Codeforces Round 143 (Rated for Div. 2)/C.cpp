/**
 *    author:  MaGnsi0
 *    created: 17.12.2024 21:29:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i]; c[i] = b[i];
        }
        for (int i = 1; i < n; ++i) {
            c[i] += c[i - 1];
        }
        vector<int64_t> ans(n + 1), f(n + 1);
        for (int i = 0; i < n; ++i) {
            int low = i, high = n - 1, j = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (c[mid] - (i ? c[i - 1] : 0) <= a[i]) {
                    j = mid; low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            f[i]++, f[j + 1]--; ans[j + 1] += a[i] - (j >= 0 ? c[j] - (i ? c[i - 1] : 0) : 0);
        }
        for (int i = 1; i <= n; ++i) {
            f[i] += f[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            ans[i] += f[i] * b[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
