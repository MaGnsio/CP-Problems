/**
 *    author:  MaGnsi0
 *    created: 05.08.2023 22:21:35
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
        int ans = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < mx) {
                ans = max(ans, mx);
            } else {
                mx = a[i];
            }
        }
        cout << ans << "\n";
    }
}
