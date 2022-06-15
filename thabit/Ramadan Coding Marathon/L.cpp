/**
 *    author:  MaGnsi0
 *    created: 21.04.2022 11:05:22
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
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = a[i] + i;
        }
        for (int i = 1; i < n; ++i) {
            b[i] = max(b[i], b[i - 1]);
        }
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1, ans = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (i - a[i] <= b[m]) {
                    ans = m + 1;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
