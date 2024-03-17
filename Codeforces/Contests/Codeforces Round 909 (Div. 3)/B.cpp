/**
 *    author:  MaGnsi0
 *    created: 28.11.2023 21:38:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int64_t ans = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k) { continue; }
            int64_t maxT = INT64_MIN;
            int64_t minT = INT64_MAX;
            for (int j = 1; j <= n / k; ++j) {
                int64_t t = a[k * j - 1] - (j > 1 ? a[k * (j - 1) - 1] : 0);
                maxT = max(maxT, t);
                minT = min(minT, t);
            }
            ans = max(ans, maxT - minT);
        }
        cout << ans << "\n";
    }
}
