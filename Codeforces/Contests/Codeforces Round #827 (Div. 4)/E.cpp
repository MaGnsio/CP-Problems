/**
 *    author:  MaGnsi0
 *    created: 14.10.2022 19:44:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> b = a;
        for (int i = 1; i < n; ++i) {
            b[i] += b[i - 1];
        }
        vector<int64_t> c = a;
        for (int i = 1; i < n; ++i) {
            c[i] = max(c[i], c[i - 1]);
        }
        for (int i = 0; i < q; ++i) {
            int k;
            cin >> k;
            int l = 0, r = n - 1, ans = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (c[m] <= k) {
                    ans = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            cout << (ans == -1 ? 0 : b[ans]) << " ";
        }
        cout << "\n";
    }
}
