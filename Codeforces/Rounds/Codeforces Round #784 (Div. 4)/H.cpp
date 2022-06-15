/**
 *    author:  MaGnsi0
 *    created: 22.04.2022 09:57:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> cnt(31, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 31; ++j) {
                cnt[j] += (1 & (a[i] >> j));
            }
        }
        int OR = 0;
        for (int i = 30; i >= 0; --i) {
            if (n - cnt[i] <= k) {
                OR |= (1 << i);
                k -= (n - cnt[i]);
            }
        }
        int ans = a[0];
        for (int i = 1; i < n; ++i) {
            ans &= a[i];
        }
        ans |= OR;
        cout << ans << "\n";
    }
}
