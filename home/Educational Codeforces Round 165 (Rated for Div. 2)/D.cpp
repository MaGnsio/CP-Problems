/**
 *    author:  MaGnsi0
 *    created: 29.04.2024 18:16:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int64_t> a(n), b(n), I(n);
        iota(I.begin(), I.end(), 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(I.begin(), I.end(), [&](int64_t i, int64_t j) {
            return a[i] < a[j];
        });
        int64_t ans = 0, not_buy = 0, total = 0;
        multiset<int64_t> items;
        for (int64_t i : I) {
            if (b[i] < a[i]) { continue; }
            total += b[i] - a[i];
            if (items.size() < k) {
                items.insert(b[i]);
                not_buy -= b[i];
            } else if (!items.empty() && *items.begin() < b[i]) {
                not_buy += *items.begin();
                items.erase(items.begin());
                items.insert(b[i]);
                not_buy -= b[i];
            }
            ans = max(ans, total + not_buy);
        }
        cout << ans << "\n";
    }
}
