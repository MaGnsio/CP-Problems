/**
 *    author:  MaGnsi0
 *    created: 02.10.2022 20:47:53
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
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += max((2 * a[0] + a[i] - 2) / (2 * a[0] - 1) - 1, 0);
        }
        cout << ans << "\n";
    }
}
