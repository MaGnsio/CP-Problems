/**
 *    author:  MaGnsi0
 *    created: 07.06.2023 03:46:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n + 1, q + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i <= n; ++i) {
            a[i] = a[i] <= q;
        }
        int64_t ans = 0, x = 0;
        for (int i = 0; i <= n; ++i) {
            if (a[i] == 0) {
                if (x >= k) {
                    ans += (x - k + 1) * (x - k + 2) / 2;
                }
                x = 0;
            } else {
                x++;
            }
        }
        cout << ans << "\n";
    }
}
