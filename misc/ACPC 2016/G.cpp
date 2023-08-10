#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<tuple<int, int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            a[i] = make_tuple(x, y, z - 1);
        }
        sort(a.begin(), a.end());
        function<bool(int64_t)> F = [&](int64_t l) {
            for (int i = 0; i < n; ++i) {
                int64_t min_y = get<1>(a[i]);
                int64_t max_y = min_y + l, cnt = 0;
                vector<int> f(k, 0);
                for (int j = 0, p = 0; j < n; ++j) {
                    if (get<1>(a[j]) < min_y || get<1>(a[j]) > max_y) { continue; }
                    while (p < j && get<0>(a[j]) - get<0>(a[p]) > l) {
                        if (min_y <= get<1>(a[p]) && get<1>(a[p]) <= max_y) {
                            cnt -= f[get<2>(a[p])] == 1;
                            f[get<2>(a[p])]--;
                        }
                        p++;
                    }
                    cnt += f[get<2>(a[j])] == 0;
                    f[get<2>(a[j])]++;
                    if (cnt == k) { return true; }
                }
            }
            return false;
        };
        int64_t low = 1, high = 2e10, ans = 0;
        while (low <= high) {
            int64_t mid = low + (high - low) / 2;
            if (F(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
