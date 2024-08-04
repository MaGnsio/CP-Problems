/**
 *    author:  MaGnsi0
 *    created: 04.08.2024 18:02:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int64_t low = a[n - 1], high = a[n - 1] + k - 1;
        for (int i = 0; i < n; ++i) {
            int64_t t = a[n - 1] - a[i];
            if ((t / k) & 1) {
                int64_t l = a[n - 1] + k - (t % k);
                int64_t r = a[n - 1] + k - 1;
                low = max(low, l);
                high = min(high, r);
            } else {
                int64_t l = a[n - 1];
                int64_t r = a[n - 1] + k - (t % k) - 1;
                low = max(low, l);
                high = min(high, r);
            }
        }
        cout << (low > high ? -1 : low) << "\n";
    }
}
