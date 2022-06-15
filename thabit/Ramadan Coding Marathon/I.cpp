/**
 *    author:  MaGnsi0
 *    created: 13.04.2022 21:58:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> pre(n), suf(n);
        pre[0] = a[0];
        pre[0] %= k;
        for (int i = 1; i < n; ++i) {
            pre[i] = a[i] + pre[i - 1];
            pre[i] %= k;
        }
        suf[n - 1] = a[n - 1];
        suf[n - 1] %= k;
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = a[i] + suf[i + 1];
            suf[i] %= k;
        }
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[suf[i]]++;
        }
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            cnt[suf[i]]--;
            ans += cnt[(k - pre[i]) % k];
        }
        cout << ans << "\n";
    }
}
