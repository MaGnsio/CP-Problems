/**
 *    author:  MaGnsi0
 *    created: 20/08/2021 10:46:19
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a) {
            cin >> x;
        }
        sort(a.begin(), a.end(), greater<int>());
        for (auto& x : b) {
            cin >> x;
        }
        sort(b.begin(), b.end(), greater<int>());
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
        }
        int l = 0, r = 1e5, res;
        while (l <= r) {
            int mid = (l + r) / 2 + n;
            int k = mid - (mid / 4);
            int x = 100 * min(mid - n, k) + (k - min(mid - n, k) ? a[k - min(mid - n, k) - 1] : 0), y = b[min(n - 1, k - 1)];
            if (x >= y) {
                res = mid - n;
                r = mid - n - 1;
            } else {
                l = mid - n + 1;
            }
        }
        cout << res << "\n";
    }
}
