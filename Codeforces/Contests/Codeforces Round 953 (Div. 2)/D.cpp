/**
 *    author:  MaGnsi0
 *    created: 17.06.2024 16:14:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t c; cin >> c;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t sum_lower = 0;
        multiset<int64_t> lower, upper;
        for (int i = 0; i < n; ++i) {
            upper.insert(a[i]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            sum_lower += a[i];
            upper.erase(upper.find(a[i]));
            if ((upper.empty() || a[i] + (i == 0) * c >= *upper.rbegin())
             && (lower.empty() || a[i] + (i == 0) * c > *lower.rbegin())
             && (i == 0 || a[i] > a[0] + c)) {
                ans[i] = 0;
                lower.insert(a[i]);
                continue;
            }
            int64_t x = sum_lower + c;
            ans[i] = i + (!upper.empty() && x < *upper.rbegin());
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
