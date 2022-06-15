/**
 *    author:  MaGnsi0
 *    created: 13.05.2022 16:34:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size() + 1;
        vector<int> a(n, 0), b(n, 0);
        for (int i = 1; i < n; ++i) {
            a[i] = a[i - 1];
            if (s[i - 1] == '0') {
                a[i]++;
            }
        }
        for (int i = 1; i < n; ++i) {
            b[i] = b[i - 1];
            if (s[i - 1] == '1') {
                b[i]++;
            }
        }
        int ans = a[n - 1];
        for (int i = 0; i < n; ++i) {
            ans = min(ans, max(a[n - 1] - a[i], b[i]));
            int l = 0, r = n - i - 2;
            while (l <= r) {
                int m = (l + r) / 2;
                int x = i + m + 1;
                if (a[x - 1] - a[i] >= b[n - 1] - b[x - 1] + b[i]) {
                    ans = min(ans, a[x - 1] - a[i]);
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            l = 0, r = n - i - 2;
            while (l <= r) {
                int m = (l + r) / 2;
                int x = i + m + 1;
                if (a[x - 1] - a[i] <= b[n - 1] - b[x - 1] + b[i]) {
                    ans = min(ans, b[n - 1] - b[x - 1] + b[i]);
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        cout << ans << "\n";
    }
}
