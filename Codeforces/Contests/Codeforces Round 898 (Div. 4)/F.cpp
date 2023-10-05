/**
 *    author:  MaGnsi0
 *    created: 03.10.2023 21:14:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        c[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            c[i] = (b[i] % b[i + 1] == 0 ? c[i + 1] : i);
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int low = i, high = c[i], j = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[mid] - (i ? a[i - 1] : 0) <= k) {
                    j = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans = max(ans, j - i + 1);
        }
        cout << ans << "\n";
    }
}
