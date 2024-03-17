/**
 *    author:  MaGnsi0
 *    created: 19.12.2023 14:02:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        iota(b.begin(), b.end(), 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(b.begin(), b.end(), [&](int i, int j) {
                return a[i] > a[j];
            });
        vector<int64_t> suf(n);
        suf[n - 1] = a[b[n - 1]];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = suf[i + 1] + a[b[i]];
        }
        vector<int> ans(n);
        ans[b[0]] = n - 1;
        for (int i = 1; i < n; ++i) {
            if (suf[i] >= a[b[i - 1]]) {
                ans[b[i]] = ans[b[i - 1]];
            } else {
                ans[b[i]] = n - i - 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
