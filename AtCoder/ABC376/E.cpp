/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 15:28:33
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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int64_t i, int64_t j) {
            return (a[i] < a[j]) || ((a[i] == a[j]) && (b[i] < b[j]));
        });
        int64_t min_sum = 0;
        multiset<int64_t> kb;
        for (int i = 0; i < k; ++i) {
            int j = I[i];
            min_sum += b[j];
            kb.insert(b[j]);
        }
        int64_t ans = min_sum * a[I[k - 1]];
        for (int i = k; i < n; ++i) {
            int j = I[i];
            ans = min(ans, (min_sum - *kb.rbegin() + b[j]) * a[j]);
            if (*kb.rbegin() > b[j]) {
                min_sum -= *kb.rbegin();
                min_sum += b[j];
                kb.erase(kb.find(*kb.rbegin()));
                kb.insert(b[j]);
            }
        }
        cout << ans << "\n";
    }
}
