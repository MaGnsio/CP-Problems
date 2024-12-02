/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 16:36:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[n - 1] > k) {
            cout << 0 << "\n";
            continue;
        }
        int ans = INT_MAX;
        for (int i = n - 1, sum = 0; i >= 0; --i) {
            sum += a[i];
            if (sum <= k) {
                ans = min(ans, k - sum);
            }
        }
        cout << ans << "\n";
    }
}
