/**
 *    author:  MaGnsi0
 *    created: 31.08.2023 22:10:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        vector<pair<int64_t, int64_t>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end(), [&](pair<int64_t, int64_t> x, pair<int64_t, int64_t> y) {
                if (x.first == y.first) {
                    return x.second < y.second;
                }
                return x.first > y.first; 
            });
        function<__int128(int64_t)> F = [&](int64_t x) {
            __int128 ans = __int128(x) * (a[0].first + a[1].first);
            __int128 y = k - 2 * x;
            ans += __int128(y) * a[0].first;
            ans -= __int128(y) * (y - 1) * a[0].second / 2;
            return ans;
        };
        int64_t low = 0, high = k / 2;
        while (high - low >= 5) {
            int64_t mid = (low + high) / 2;
            if (F(mid) < F(mid + 1)) {
                low = mid;
            } else {
                high = mid + 1;
            }
        }
        int64_t ans = 0;
        for (int i = low; i <= high; ++i) {
            ans = max(ans, int64_t(F(i)));
        }
        cout << ans << "\n";
    }
}
