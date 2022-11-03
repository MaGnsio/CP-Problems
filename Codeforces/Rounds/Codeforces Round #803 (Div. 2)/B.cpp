/**
 *    author:  MaGnsi0
 *    created: 28.06.2022 16:34:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (k > 1) {
            int ans = 0;
            for (int i = 1; i < n - 1; ++i) {
                ans += (a[i] > a[i - 1] + a[i + 1]);
            }
            cout << ans << "\n";
        } else {
            cout << (n - 1) / 2 << "\n";
        }
    }
}
