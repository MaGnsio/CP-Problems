/**
 *    author:  MaGnsi0
 *    created: 08.01.2023 16:58:14
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
        vector<int> I(n);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return a[i] < a[j];
            });
        function<bool(int)> ok = [&](int m) {
            if (a[n - m] <= k) {
                int nk = k - a[n - m], cnt = 1;
                for (int i = 0; i < n; ++i) {
                    if (I[i] == n - m) {
                        continue;
                    }
                    if (a[I[i]] <= nk) {
                        nk -= a[I[i]];
                        cnt++;
                    }
                }
                if (cnt >= n - m) {
                    return true;
                }
            }
            int nk = k, cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (I[i] == n - m) {
                    continue;
                }
                if (a[I[i]] <= nk) {
                    nk -= a[I[i]];
                    cnt++;
                }
            }
            if (cnt >= n - m + 1) {
                return true;
            }
            return false;
        };
        int l = 1, r = n, ans = n + 1;
        while (l <= r) {
            int m = (l + r) / 2;
            //win at least n - m when the (n-m)_th doesn't win vs. me
            //win at least n - m + 1 when the (n-m)_th win vs. me
            if (ok(m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << ans << "\n";
    }
}
