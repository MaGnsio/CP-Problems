/**
 *    author:  MaGnsi0
 *    created: 22.04.2022 09:57:32
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> pre(n + 1, 0), suf(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = a[i] + pre[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = a[i] + suf[i + 1];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = i, r = n, res = 0;
            while (l <= r) {
                int m = (l + r) / 2;
                if (suf[m] == pre[i]) {
                    res = i + (n - m);
                    break;
                }
                if (suf[m] < pre[i]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
}
