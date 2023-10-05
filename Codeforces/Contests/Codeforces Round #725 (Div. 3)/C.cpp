/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 16:23:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n);
        for (auto& x : v) {
            cin >> x;
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int s = i + 1, e = n - 1, a = -1, b = -1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (v[i] + v[mid] >= l) {
                    a = mid;
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            s = i + 1, e = n - 1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (v[i] + v[mid] <= r) {
                    b = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            if (a == -1 || b == -1) {
                continue;
            }
            ans += b - a + 1;
        }
        cout << ans << "\n";
    }
}
