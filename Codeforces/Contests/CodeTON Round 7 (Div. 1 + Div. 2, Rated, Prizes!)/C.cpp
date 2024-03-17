/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 17:04:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x; cin >> x;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        iota(c.begin(), c.end(), 0);
        sort(c.begin(), c.end(), [&](int i, int j) {
                return a[i] > a[j];
            });
        vector<int> ans(n);
        for (int i = 0; i < x; ++i) {
            int j = c[i];
            ans[j] = b[x - i - 1];
        }
        for (int i = x; i < n; ++i) {
            int j = c[i];
            ans[j] = b[n - (i - x) - 1];
        }
        for (int i = 0; i < n; ++i) {
            x -= a[i] > ans[i];
        }
        if (x != 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
