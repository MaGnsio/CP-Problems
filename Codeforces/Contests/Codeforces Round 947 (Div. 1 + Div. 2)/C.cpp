/**
 *    author:  MaGnsi0
 *    created: 28.05.2024 22:36:25
**/
#include <bits/stdc++.h>

using namespace std;

const int Nax = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> a_ = a;
        sort(a_.begin(), a_.end());
        function<bool(int)> ok = [&](int x) {
            vector<int> b(n);
            for (int i = 0; i < n; ++i) {
                b[i] = (a[i] >= x ? 1 : -1);
            }
            for (int i = 1; i < n; ++i) {
                b[i] += b[i - 1];
            }
            int min_pref = 0;
            for (int i = 1; i < n; ++i) {
                if (b[i] - min_pref > 0) {
                    return true;
                }
                min_pref = min(min_pref, b[i - 1]);
            }
            return false;
        };
        int low = 0, high = n - 1, ans = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ok(a_[mid])) {
                ans = a_[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
