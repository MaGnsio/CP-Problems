/**
 *    author:  MaGnsi0
 *    created: 27.03.2022 16:27:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> l >> r;
        n = r - l + 1;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> cnt1(18, 0), cnt2(18, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 18; ++j) {
                cnt1[j] += ((a[i] >> j) & 1);
            }
            for (int j = 0; j < 18; ++j) {
                cnt2[j] += (((l + i) >> j) & 1);
            }
        }
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < 18; ++i) {
            if (cnt1[i] != cnt2[i]) {
                for (int j = 0; j < ans.size(); ++j) {
                    ans[j] |= (1 << i);
                }
            } else if (n - cnt1[i] == cnt2[i]) {
                int m = (int)ans.size();
                for (int j = 0; j < m; ++j) {
                    ans.push_back(ans[j] | (1 << i));
                }
            }
        }
        for (int i = 0; i < (int)ans.size(); ++i) {
            vector<int> b = a;
            for (int j = 0; j < n; ++j) {
                b[j] ^= ans[i];
            }
            sort(b.begin(), b.end());
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (b[j] != l + j) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << ans[i] << "\n";
                break;
            }
        }
    }
}
