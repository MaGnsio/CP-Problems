/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 17:09:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t k; cin >> k;
        string s; cin >> s;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = (s[i] == '1' ? +1 : -1);
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        sort(a.begin(), a.begin() + n - 1);
        int64_t ans = -1, minus = 0;
        for (int m = 1; m <= n; ++m) {
            minus += (m - 1 ? a[m - 2] : 0);
            int64_t val = (m - 1) * a[n - 1] - minus;
            if (val >= k) {
                ans = m;
                break;
            }
        }
        cout << ans << "\n";
    }
}
