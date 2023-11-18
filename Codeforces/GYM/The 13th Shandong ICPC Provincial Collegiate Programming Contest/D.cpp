/**
 *    author:  MaGnsi0
 *    created: 13.10.2023 19:52:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> v(n), w(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i] >> w[i];
        }
        function<bool(int64_t)> F = [&](int64_t x) {
            vector<pair<int64_t, int64_t>> a;
            multiset<int64_t> wNeg;
            for (int i = 0; i < n; ++i) {
                if (v[i] >= x) {
                    a.emplace_back(v[i], w[i]);
                } else {
                    wNeg.insert(-w[i]);
                }
            }
            sort(a.begin(), a.end(), [](pair<int64_t, int64_t> x, pair<int64_t, int64_t> y) {
                    return x.first + x.second < y.first + y.second;
                });
            for (auto [v_, w_] : a) {
                auto it = wNeg.lower_bound(x - v_ - w_);
                if (it != wNeg.end()) {
                    wNeg.erase(it);
                }
            }
            return wNeg.empty();
        };
        int64_t low = 1, high = 1e9, ans = 1;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
