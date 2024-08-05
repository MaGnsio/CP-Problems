/**
 *    author:  MaGnsi0
 *    created: 25.06.2024 18:09:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t L, R;
        cin >> L >> R;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n; /*_*/) {
            int low = i, high = n - 1, j = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[mid] - (i ? a[i - 1] : 0) >= L) {
                    j = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (j == -1) { break; }
            if (a[j] - (i ? a[i - 1] : 0) > R) { i++; continue; }
            ans++; i = j + 1;
        }
        cout << ans << "\n";
    }
}
