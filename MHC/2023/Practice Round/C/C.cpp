/**
 *    author:  MaGnsi0
 *    created: 22.09.2023 23:59:36
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 5e10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int64_t> a(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; ++i) {
            cin >> a[i];
        }
        function<int64_t()> solve = [&]() {
            int64_t res = OO;
            vector<int64_t> b(n), c(n);
            for (int i = 0; i < n; ++i) {
                if (i < n - 1) {
                    b[i] = a[i] + a[2 * n - i - 2];
                }
                if (i) {
                    c[i] = a[i] + a[2 * n - i - 1];
                }
            }
            vector<bool> sameb(n), samec(n);
            sameb[0] = samec[n - 1] = true;
            for (int i = 1; i < n; ++i) {
                sameb[i] = sameb[i - 1] && b[i] == b[i - 1];
            }
            for (int i = n - 2; i >= 0; --i) {
                samec[i] = samec[i + 1] && c[i] == c[i + 1];
            }
            for (int i = 0; i < n; ++i) {
                bool X = (i ? sameb[i - 1] : true);
                bool Y = (i + 1 < n ? samec[i + 1] : true);
                bool Z = (i && i + 1 < n ? b[i - 1] == c[i + 1] : true);
                int64_t val = (i ? b[i - 1] : c[i + 1]) - a[i];
                if (X && Y && Z && val > 0) {
                    res = min(res, val);
                }
            }
            return res;
        };
        int64_t ans = OO;
        if (n == 1) {
            ans = 1;
        } else {
            sort(a.begin(), a.end());
            ans = min(ans, solve());
            sort(a.rbegin(), a.rend());
            ans = min(ans, solve());
        }
        cout << "Case #" << t << ": ";
        cout << (ans == OO ? -1 : ans) << "\n";
    }
}
