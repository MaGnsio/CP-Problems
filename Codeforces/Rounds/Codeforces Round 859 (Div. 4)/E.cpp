/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 02:14:22
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
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int l = 0, r = n - 1, ans = 1;
        while (l <= r) {
            int m = (l + r) / 2;
            cout << "? " << m + 1;
            for (int i = 0; i <= m; ++i) {
                cout << " " << i + 1;
            }
            cout << endl;
            int sum;
            cin >> sum;
            if (sum > a[m]) {
                ans = m + 1;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << "! " << ans << endl;
    }
}
