/**
 *    author:  MaGnsi0
 *    created: 06.08.2022 16:33:59
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
        bool ok = true;
        vector<int64_t> ans(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            int64_t l = 0, r = 2 * (n - 1), j = -1;
            while (l <= r) {
                int64_t m = (l + r) / 2;
                if (m * m - i < n) {
                    j = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            while (j * j >= i && ans[j * j - i] != -1) {
                j--;
            }
            if (j * j < i) {
                ok = false;
                break;
            }
            ans[j * j - i] = i;
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
