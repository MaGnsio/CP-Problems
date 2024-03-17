/**
 *    author:  MaGnsi0
 *    created: 20.11.2023 16:00:10
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 0, last = OO;
        for (int i = n - 1; i >= 0; --i) {
            int64_t low = 1, high = a[i], z = 1;
            while (low <= high) {
                int64_t mid = (low + high) / 2;
                int64_t x = (a[i] + mid - 1) / mid;
                int64_t y = a[i] / mid;
                if (y <= x && x <= last) {
                    z = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans += z - 1;
            last = a[i] / z;
        }
        cout << ans << "\n";
    }
}
