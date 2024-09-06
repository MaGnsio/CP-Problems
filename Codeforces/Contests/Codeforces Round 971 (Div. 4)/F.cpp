/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 01:29:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t Q; cin >> Q;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        function<int64_t(int64_t, int64_t, int64_t)> G = [&](int64_t c, int64_t low, int64_t high) {
            int64_t j1 = (low + c) % n;
            int64_t j2 = (high + c) % n;
            if (j1 > j2) {
                return a[n - 1] - (j1 ? a[j1 - 1] : int64_t(0)) + a[j2];
            }
            return a[j2] - (j1 ? a[j1 - 1] : int64_t(0));
        };
        function<int64_t(int64_t, int64_t)> F = [&](int64_t low, int64_t high) {
            int64_t clow = low / n;
            int64_t slow = low % n;
            int64_t elow = min(n - 1, slow + high - low);
            int64_t chigh = high / n;
            int64_t ehigh = high % n;
            int64_t shigh = max(int64_t(0), ehigh - (high - low));
            if (clow == chigh && slow == shigh && elow == ehigh) {
                return G(clow, slow, elow);
            }
            int64_t rem = (high - low + 1) - (elow - slow + 1) - (ehigh - shigh + 1);
            assert(rem % n == 0);
            int64_t res = (rem / n) * a[n - 1] + G(clow, slow, elow) + G(chigh, shigh, ehigh);
            return res;
        };
        while (Q--) {
            int64_t low; cin >> low; low--;
            int64_t high; cin >> high; high--;
            cout << F(low, high) << "\n";
        }
    }
}
