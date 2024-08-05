/**
 *    author:  MaGnsi0
 *    created: 23.06.2024 18:48:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i] % k].push_back(a[i]);
        }
        int odds = 0;
        for (auto& [_, b] : mp) {
            odds += (int)b.size() & 1;
        }
        if (odds > 1) {
            cout << "-1\n";
            continue;
        }
        int64_t ans = 0;
        for (auto& [_, b] : mp) {
            int m = (int)b.size();
            sort(b.begin(), b.end());
            if (m & 1) {
                vector<int64_t> pre(m), suf(m);
                for (int i = 1; i < m; i += 2) {
                    pre[i] = (b[i] - b[i - 1]) / k;
                }
                for (int i = 1; i < m; ++i) {
                    pre[i] += pre[i - 1];
                }
                for (int i = m - 2; i >= 0; i -= 2) {
                    suf[i] = (b[i + 1] - b[i]) / k;
                }
                for (int i = m - 2; i >= 0; --i) {
                    suf[i] += suf[i + 1];
                }
                int64_t val = INT64_MAX;
                for (int skip = 0; skip < m; ++skip) {
                    int64_t L = (skip ? pre[skip - 1] : 0LL);
                    int64_t R = (skip != m - 1 ? suf[skip + 1] : 0LL);
                    int64_t add = (skip & 1 ? (b[skip + 1] - b[skip - 1]) / k : 0LL);
                    val = min(val, L + add + R);
                }
                ans += val;
            } else {
                for (int i = 1; i < m; i += 2) {
                    ans += (b[i] - b[i - 1]) / k;
                }
            }
        }
        cout << ans << "\n";
    }
}
