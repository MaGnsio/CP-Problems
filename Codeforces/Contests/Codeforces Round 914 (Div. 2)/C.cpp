/**
 *    author:  MaGnsi0
 *    created: 19.12.2023 14:21:48
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
        if (k > 2) {
            cout << 0 << "\n";
            continue;
        }
        sort(a.begin(), a.end());
        multiset<int64_t> a_pos, a_neg;
        for (int i = 0; i < n; ++i) {
            a_pos.insert(a[i]);
            a_neg.insert(-a[i]);
        }
        int64_t ans = a[0];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int64_t newx = a[j] - a[i];
                if (k == 1) {
                    ans = min({ans, a[0], newx});
                    continue;
                }
                auto it1 = a_pos.lower_bound(newx);
                int64_t diff1 = (it1 == a_pos.end() ? INT64_MAX : (*it1 - newx));
                auto it2 = a_neg.lower_bound(-newx);
                int64_t diff2 = (it1 == a_pos.end() ? INT64_MAX : (newx + *it2));
                ans = min({ans, a[0], newx, diff1, diff2});
            }
        }
        cout << ans << "\n";
    }
}
