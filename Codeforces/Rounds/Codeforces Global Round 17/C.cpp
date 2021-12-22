/**
 *    author:  MaGnsi0
 *    created: 24.11.2021 14:45:28
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        auto ok = [=](int m) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (b[i] >= cnt && a[i] >= m - cnt - 1) {
                    cnt++;
                }
            }
            return (cnt >= m);
        };
        int l = 1, r = n, res = 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (ok(m)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << res << "\n";
    }
}
